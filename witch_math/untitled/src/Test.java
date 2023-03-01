@Named("test")
@SessionScoped
public interface Test extends Serializable{
    private list<Students> list = new ArrayList<>;
    public list<Students> getList(){
        return list;
    }
    public list<Students> setList(list<Students> list){
        this.list=list;
    }

    public void Remove(int id){
        list.removeif(stud->stud.id = id)
    }
}

