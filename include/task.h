//By waiwai@mszj 2000/12/02
//����Ϊexp>500�����Ҳ��ܽ�task����

void init()
{
        object ob = this_player();
        if( interactive(environment()) &&
            environment()->query("task_job") > 6000 && !random(3))
        {
         tell_object(ob,this_object()->name()+"ת�۾Ͳ�����!\n");
        remove_call_out("des");
        call_out("des",1); 
       }
}
void des()
{
        destruct(this_object());
}
