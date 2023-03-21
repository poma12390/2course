import logging
import openai
from telegram import Update
from telegram.ext import Updater, CommandHandler, MessageHandler, CallbackContext, Filters

# Replace 'YOUR_API_TOKEN' with the API token you got from the BotFather
API_TOKEN = '6145516516:AAGZlZfnLYpV5FZR3AWQjvVAXwWQcX8aW6I'
GPT_API_KEY = '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'

openai.api_key = GPT_API_KEY

query = [
    {"role": "system",
     "content": "You are John Galt from the book Atlas Shrugged. You answer questions honestly, but do it in a sarcastic way like Chandler from Friends."},
    {"role": "user", "content": "How to make a nation thrive?"}
]


def start(update: Update, context: CallbackContext) -> None:
    update.effective_message.reply_text(
        'Добро пожаловать! Введите сообщение и нажмите отправить, я отправлю его в ChatGPT-3 и верну ответ.')


def send_to_gpt3(update: Update, context: CallbackContext) -> None:
    message_text = update.effective_message.text
    prompt = message_text

    try:
        response = openai.Completion.create(
            engine="text-davinci-002",
            prompt=prompt,
            temperature=0.3,
            max_tokens=4001,
            frequency_penalty=0,
            presence_penalty=0,
            echo=True,
            stop = None
        )
        print(response)
        generated_text = response.choices[0].text.strip()
        update.effective_message.reply_text(generated_text)
    except Exception as e:
        update.effective_message.reply_text(f'Ошибка: Не удалось отправить сообщение в ChatGPT-3. Ошибка: {e}')


persona = """You are a helpful cooking expert. You answer question by providing a short explanation and a list of easy to follow steps. You list ingredients, tools, and instructions."""
tell_user = print
ask_user = input


def talk_with():
    message_history = []
    while True:
        user_input = ask_user()
        if user_input == "":
            return message_history

        message_history.append({"role": "user", "content": user_input})
        query.extend(message_history)
        result = openai.ChatCompletion.create(
            model="gpt-3.5-turbo",
            messages=query
        )
        gpt_message = result["choices"][0]["message"]
        message_history.append({"role": gpt_message["role"], "content": gpt_message["content"]})
        tell_user("GPT: " + gpt_message["content"])


def main() -> None:
    updater = Updater(API_TOKEN)

    dispatcher = updater.dispatcher
    dispatcher.add_handler(CommandHandler('start', start))
    dispatcher.add_handler(MessageHandler(Filters.text & ~Filters.command, send_to_gpt3))
    dispatcher.add_handler(CommandHandler('test', talk_with))

    updater.start_polling()
    updater.idle()


if __name__ == '__main__':
    main()
