package validators;

import javax.faces.application.FacesMessage;
import javax.faces.component.UIComponent;
import javax.faces.context.FacesContext;
import javax.faces.validator.FacesValidator;
import javax.faces.validator.Validator;
import javax.faces.validator.ValidatorException;

@FacesValidator("validatorY")
public class ValidatorY implements Validator {
    private static final float MAX_Y = 5;
    private static final float MIN_Y = -5;

    @Override
    public void validate(FacesContext facesContext, UIComponent uiComponent, Object o) throws ValidatorException {
        if (o == null) {
            throw new ValidatorException(
                    new FacesMessage(FacesMessage.SEVERITY_ERROR, null,
                            "Некорректное X"));
        }
        double yValue = Double.parseDouble(String.valueOf(o));
        if (yValue < MIN_Y || yValue > MAX_Y) throw new ValidatorException(
                new FacesMessage(FacesMessage.SEVERITY_ERROR, null,
                      "Выход за пределы диапазона")
        );
    }
}