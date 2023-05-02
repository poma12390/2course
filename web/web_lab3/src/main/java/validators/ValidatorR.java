package validators;

import javax.faces.application.FacesMessage;
import javax.faces.component.UIComponent;
import javax.faces.context.FacesContext;
import javax.faces.validator.FacesValidator;
import javax.faces.validator.Validator;
import javax.faces.validator.ValidatorException;

@FacesValidator("validatorR")
public class ValidatorR implements Validator {
    private static final float MAX_R = 3;
    private static final float MIN_R = -5;

    @Override
    public void validate(FacesContext facesContext, UIComponent uiComponent, Object o) throws ValidatorException {
        if (o == null) {
            throw new ValidatorException(
                    new FacesMessage(FacesMessage.SEVERITY_ERROR, null,
                            "Введите R"));
        }
        double yValue = Double.parseDouble(String.valueOf(o));
        if (yValue <= MIN_R || yValue >= MAX_R) throw new ValidatorException(
                new FacesMessage(FacesMessage.SEVERITY_ERROR, null,
                        "Выход за пределы диапазона")
        );
    }
}