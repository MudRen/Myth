
// CMDS overview.c
// Last Modified by zeus@刀剑笑 Jan.13.2000

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
                        str = "共有"+sizeof(ob)+"个使用者物件";
                        break;
                case "living":
                        ob = livings();
                        str = "共有"+sizeof(ob)+"个生物(含使用者)物件";
                        break;
                case "char":
                        ob = objects( (: $1->is_character() && !clonep($1) :) );
                        str = "共有"+sizeof(ob)+"种人物物件 master copy 被载入";
                        break;
                case "npc":
                        ob = filter_array( livings(), (: $1->is_character() && !userp($1) && clonep($1) :) );
                        str = "共有"+sizeof(ob)+"个 NPC 物件";
                        break;
                case "combat":
                        ob = objects( (: $1->is_fighting() :) );
                        str = "共有"+sizeof(ob)+"个人物正在战斗状态";
                        break;
                case "kill":
                        ob = objects( (: $1->is_killing() && $1->is_fighting() :) );
                        str = "共有"+sizeof(ob)+"个人物正在性命相搏的战斗状态";
                        break;
                case "hunt":
                        ob = objects( (: $1->is_killing() :) );
                        str = "共有"+sizeof(ob)+"个人物正和其他人物互相仇恨";
                        break;
                case "heart beat":
                        ob = objects( (: query_heart_beat :) );
                        str = "共有"+sizeof(ob)+"个物件的 heart beat 为有效状态";
                        break;
                case "virtual":
                        ob = objects( (: virtualp :) );
                        str = "共有"+sizeof(ob)+"个虚拟物件";
                        break;
                case "room":
                        ob = objects( (: function_exists("create_door", $1) :) );
                        str = "共有"+sizeof(ob)+"个房间";
                        break;
                case "special room":
                        // inherits won't work if master copy got cleaned up.
                        if( !find_object(ROOM) ) ROOM->foo();
                        ob = objects( (: inherits(ROOM, $1) :) );
                        str = "共有"+sizeof(ob)+"个物件继承标准房间";
                        break;
                case "equip":
                        // inherits won't work if master copy got cleaned up.
                        if( !find_object(F_EQUIP) ) F_EQUIP->foo();
                        ob = objects( (: inherits(F_EQUIP, $1) :) );
                        str = "共有"+sizeof(ob)+"个物件继承标准装备";
                        break;
                case "object":
                        ob = objects();
                        str = "共有"+sizeof(ob)+"个物件被载入";
                        break;
                default:
                        return notify_fail("指令格式：overview <topic>\n");
        }
        m = 0;
        i = sizeof(ob);
        while(i--)
                m += memory_info(ob[i]);
        str2 = "总共使用"+m+"bytes 记忆体";
        if( sizeof(ob) )
                str3 = "平均每个物件使用"+m/sizeof(ob)+"bytes 记忆体";

     sstr = sprintf("%-15s    %-15s %-15",str, str2, str3);
     me->start_more(sstr);
                
        return 1;
}

int help()
{
        write(@TEXT
指令格式：overview <主题>

user:           userp()
living:         living()
room:           function_exists("create_door", ob);
TEXT
        );
        return 1;
}

