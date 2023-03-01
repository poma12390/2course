import {Component} from "@angular/core";

@Component({
  selector='test',
  template:
    <form>
      <h1>Форма на ПСЖ</h1>
      <input type="text" name="firstName" placeholder="Имя" [(ngModel)]="firstName">
      <input type="text" name="lastName" placeholder="Фамилия" [(ngModel)]="lastName">
      <input type="date" name="lastName" [(ngModel)]="date">
    </form>


})

export class Test{
  firstName="";
  http: HttpClient;

  submit(){
    const body = {login:firstName, pass:lastName};
    this.http.post('jopa', body);
  }
}
