void check_owner();
void destroy(object ob);

void init()
{
        check_owner();
}


void check_owner()
{
        object ob =this_object();
        object me =environment(ob);
if ( !me->query("gongs/all") && !wizardp(me))
           destroy(ob);
}
void destroy(object ob)
{
        write(ob->query("name")+"���Ĳ����ˣ� \n");
        destruct(ob);
        return;
}
