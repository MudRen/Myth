// kantou.c
// modify by happ@YSZZ

inherit F_CLEAN_UP;

//#include <new_ride.h>
#include <ansi.h>
#include <dbase.h>

int main(object me, string arg)
{
        object obj,*ob,toulu,corpse;
        object wield1,wield2;
        object *inv;
        mapping weapon_prop;

        string *killer, callname;
        int i,count;
        int value2;
        if( environment(me)->query("no_fight") )
                return notify_fail("���ﲻ׼¶��������\n");

        if( !arg )
                return notify_fail("����Ҫ˭��ͷ­��\n");

        if(!obj)
                obj = present(arg, environment(me));

        if(!obj )
                return notify_fail("����û��������ˡ�\n");

        if(!obj->is_corpse() )
                return notify_fail("�������ɱ������ˡ�\n");

        if(obj->query("name")=="���õ�ʬ��"
                 || obj->query("name")=="���õ���ͷʬ��"
                 || obj->query("name")=="���õ���ͷŮʬ"
                 || obj->query("name")=="���õ���ͷ��ʬ"
                 )
                return notify_fail("�����Ǹ��õ�ʬ���ˡ�\n");

        if(obj->query("name")=="��ͷ��ʬ��"
                 || obj->query("name")=="��ͷ����ʬ"
                 || obj->query("name")=="��ͷ��Ůʬ"
                 )
                return notify_fail("���ǲ���������ʬ�塣\n");

        if(arg!="corpse" )
                return notify_fail("���ǲ���������ʬ�塣\n");

        if(obj==me)
                return notify_fail("�������أ�\n");

        if(!wield1=me->query_temp("weapon"))
                return notify_fail("��Ӧ������������\n");

        if(((string)wield1->query("skill_type")!="sword"
             && ((string)wield1->query("skill_type")!="blade")))
                return notify_fail("��Ӧ���Ұѽ������ǵ�ʲô�ġ�\n");

        message_vision("\n$N���һ�£���$n��ͷ����������\n"

                        +HIR+"��Ѫ����$Pһ��\n"+NOR, me, obj);
                me->add("bellicosity", 5);
//add by yudian
                 obj->set("killer", me->query("id"));
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]->query("equipped")
                        && inv[i]->query("armor_type")=="cloth"
                          && !(int)inv[i]->query("blood_onit")) {
                                inv[i]->set("blood_onit",1);
                                inv[i]->set("name",HIR"ճ����Ѫ��"NOR+inv[i]->query("name"));
                                continue;
                        }
        }

        if( objectp(corpse = CHAR_D->make_wutoucorpse(obj)) )
        {
                message_vision("ֻ������Ѫ���ڲ��ϵش�"+corpse->query("name")+
                        "�Ķϲ����˳�����\n",me);
                corpse->move(environment(me));
        
        }
        else
                write("���ܴ�����ͷʬ�壬�������ʦ��\n");
        if( objectp(toulu = CHAR_D->make_toulu(obj) ))
{ if (obj->query("killer")) 
   toulu->set("killer",obj->query("killer"));
                toulu->move(me);
}
        else
                write("���ܴ���ͷ­���������ʦ��\n");
                destruct(obj);
                return 1;

}

int help(object me)
{
  write(@HELP
ָ���ʽ : cut corpse

����ĳ�����˵�ͷ­��
HELP
    );
    return 1;
}
