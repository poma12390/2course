<template>
  <input v_model="message_value" placeholder="message">
  <button @click="send">submit</button>

</template>

<script>
export default {
  data() {
    return {
      message_value: '',
      history: []
    }
  },
  methods: {
    send() {
      this.history.push(this.message_value);
      this.history.push("debil");
      this.message_value = "";
    }
  }
}
</script>
