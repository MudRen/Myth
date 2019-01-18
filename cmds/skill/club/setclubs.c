
//Edited by Wuyou@sk_sjsh 2003-4-8

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string id,club_name;
        object ob;
        int level;

        seteuid(getuid());

        if (! SECURITY_D->valid_grant(me, "(arch)")) return 0;

        if(!arg) 
                return notify_fail("ָ���ʽ : setclub <ĳ��> <ĳ����>\n");
 
        if( sscanf(arg, "%s %s", id, club_name)!=2 ) 
                return notify_fail("ָ���ʽ : setclub <ĳ��> <ĳ����>\n");

        ob = present(id, environment(me));
        if (!ob) ob = find_player(id);
        if (!ob) ob = find_living(id);
        if (!ob) return notify_fail("û�������ม�\n");
                
        ob->delete("club");
        ob->set("club", club_name);
        ob->set("club_level", 10);
        ob->set("club_master", 1);
              
        message_vision("$N��$n����Ϊ"+club_name+"�Ĵ�ʼ�ˡ�\n",me,ob);
        ob->save();
        
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : setclub <ĳ��> <ĳ����>

��һ���������Ϊ����ͷ�졣
HELP
    );
    return 1;
}





