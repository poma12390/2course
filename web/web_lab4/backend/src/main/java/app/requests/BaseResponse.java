package app.requests;

public class BaseResponse {

    private int status;

    private Object answer;

    public BaseResponse(int status, Object answer) {
        this.status = status;
        this.answer = answer;
    }

    public int getStatus() {
        return status;
    }

    public void setStatus(int status) {
        this.status = status;
    }

    public Object getAnswer() {
        return answer;
    }

    public void setAnswer(String answer) {
        this.answer = answer;
    }
}
