
// CMDS overview.c
// Last Modified by zeus@����Ц Jan.13.2000

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object *ob;
        int i, m;
        string str="",str2="",str3="";       
           string sstr="";
        switch(arg) {
                case "user":
                        ob = users();
                        str = "����"+sizeof(ob)+"��ʹ�������";
                        break;
                case "living":
                        ob = livings();
                        str = "����"+sizeof(ob)+"������(��ʹ����)���";
                        break;
                case "char":
                        ob = objects( (: $1->is_character() && !clonep($1) :) );
                        str = "����"+sizeof(ob)+"��������� master copy ������";
                        break;
                case "npc":
                        ob = filter_array( livings(), (: $1->is_character() && !userp($1) && clonep($1) :) );
                        str = "����"+sizeof(ob)+"�� NPC ���";
                        break;
                case "combat":
                        ob = objects( (: $1->is_fighting() :) );
                        str = "����"+sizeof(ob)+"����������ս��״̬";
                        break;
                case "kill":
                        ob = objects( (: $1->is_killing() && $1->is_fighting() :) );
                        str = "����"+sizeof(ob)+"���������������ಫ��ս��״̬";
                        break;
                case "hunt":
                        ob = objects( (: $1->is_killing() :) );
                        str = "����"+sizeof(ob)+"�����������������ﻥ����";
                        break;
                case "heart beat":
                        ob = objects( (: query_heart_beat :) );
                        str = "����"+sizeof(ob)+"������� heart beat Ϊ��Ч״̬";
                        break;
                case "virtual":
                        ob = objects( (: virtualp :) );
                        str = "����"+sizeof(ob)+"���������";
                        break;
                case "room":
                        ob = objects( (: function_exists("create_door", $1) :) );
                        str = "����"+sizeof(ob)+"������";
                        break;
                case "special room":
                        // inherits won't work if master copy got cleaned up.
                        if( !find_object(ROOM) ) ROOM->foo();
                        ob = objects( (: inherits(ROOM, $1) :) );
                        str = "����"+sizeof(ob)+"������̳б�׼����";
                        break;
                case "equip":
                        // inherits won't work if master copy got cleaned up.
                        if( !find_object(F_EQUIP) ) F_EQUIP->foo();
                        ob = objects( (: inherits(F_EQUIP, $1) :) );
                        str = "����"+sizeof(ob)+"������̳б�׼װ��";
                        break;
                case "object":
                        ob = objects();
                        str = "����"+sizeof(ob)+"�����������";
                        break;
                default:
                        return notify_fail("ָ���ʽ��overview <topic>\n");
        }
        m = 0;
        i = sizeof(ob);
        while(i--)
                m += memory_info(ob[i]);
        str2 = "�ܹ�ʹ��"+m+"bytes ������";
        if( sizeof(ob) )
                str3 = "ƽ��ÿ�����ʹ��"+m/sizeof(ob)+"bytes ������";

     sstr = sprintf("%-15s    %-15s %-15",str, str2, str3);
     me->start_more(sstr);
                
        return 1;
}

int help()
{
        write(@TEXT
ָ���ʽ��overview <����>

user:           userp()
living:         living()
room:           function_exists("create_door", ob);
TEXT
        );
        return 1;
}

