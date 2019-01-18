//cwho.c
//Created by wuyou@sk_sjsh 2000/4/8 


#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

#include "/cmds/skill/valid_system.h"
int sort_user(object,object);

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
        string str,load,cmds,comp, *option, fname = "";
        object *list, *ob,ob1;
        int i, t_ppl_cnt, cnt, count, wcnt = 0;
        int opt_long, opt_id, opt_wiz, opt_party,opt_male,opt_female;

    if (!valid_system(me)) return 0;
        if( arg ) {

                option = explode(arg, " ");
                i = sizeof(option);
                while( i-- )
                        switch(option[i]) {
                                case "-l": opt_long = 1; break;
                                case "-i": opt_id = 1; break;
                                case "-p": opt_party = 1; break;
                                default:
                                        if (!ob1 ) ob1 = find_player(option[i]);
                                        if (!ob1) ob1 = find_living(option[i]);
                                        if ((!ob1) && (option[i] =="me")) ob1=me;
                                        if (!ob1) return notify_fail("û�������һ��������\nָ���ʽ : who [i] [-l] [-p]\n");
                                        if (!ob1 || wizardp(ob1) ) return notify_fail("û�������һ��������\nָ���ʽ : who [-i] [-l] [-p]\n");
                                        me = ob1; opt_party = 1;


                                        return notify_fail("ָ���ʽ��who [-l|-i|-p]\n");
                        }
        }

        if( opt_long && !wizardp(me)) {
                if( (int)me->query("sen") < 20 )
                        return notify_fail("��ľ���̫���ˣ�û�а취��֪������ҵ���ϸ���ϡ�\n");
                me->receive_damage("sen", 20);
        }

        str = HIR"��"HIW+MUD_NAME+HIW" Ŀǰ";
        if(opt_party)
                if(me->query("club"))
                        str += HIG+me->query("club")+HIW"������У�";
                else str += "����"HIC"�ް�����ʿ"HIW"�У�";
      
        else if(opt_long) str += "����У�";

        else str += "��������У�";

     str += NOR"\n������������������������������������������������������������������������������������\n"NOR;
        ob = filter_array(objects(), (: userp :));
        if (opt_party)
                ob = filter_array(ob, (: $1->query("club") ==
                        $2->query("club") :), me);
        list = sort_array(ob, (: sort_user :));
        t_ppl_cnt = 0;
        cnt = 0;
        if(opt_long) {
                i = sizeof(list);
                while( i-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[i]) ) continue;
                        if( !me->visible(list[i]) ) continue;
                        if (interactive(list[i])) t_ppl_cnt++;
                        else cnt++;
                        str = sprintf("%s%12s%s%s\n",
                                str,
                                RANK_D->query_rank(list[i]),
                                interactive(list[i])?(query_idle(list[i]) > 180?HIM "*"NOR:" "):HIR "#" NOR,
                                list[i]->short(1)
                        );
                }
        } else {
                i = sizeof(list);
                count = 0;
                while( i-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[i]) ) continue;
                        if( !me->visible(list[i]) ) continue;
                        if (!wiz_level(list[i]) && fname != list[i]->query("club")) {
                            fname = list[i]->query("club");
                            if (count % 7) str += "\n";
                            str += sprintf( "%-15s" NOR, (fname?fname:"��ͨ����") + "��");
                            count = 1;
                        }
                   
                        if (!(count%7)) {
                                count++;
                                str += "               ";
                        }
                        str = sprintf("%s%s%s%-9s"NOR"%s",
                                str,
                                interactive(list[i])?(query_idle(list[i]) > 180?HIM "*"NOR:" "):HIR "#"NOR,
                                list[i]->query("nopk")?CYN +"":NOR+"",
                                opt_id?capitalize(list[i]->query("id")): list[i]->name(1),
                                ++count%7 ? "": "\n"
                        );
                        if (interactive(list[i])) t_ppl_cnt++;
                        else cnt++;
                }
                if( count%7 ) str += "\n";
        }
   str += "������������������������������������������������������������������������������������\n"NOR;
 
         load=query_load_average();

        if(sscanf(load,"%s cmds/s, %s comp lines/s", cmds,comp)!=2) {
                str = sprintf("%s�� %d λ��������У�%d λ��Ҷ����У�ϵͳִ�����ʣ�%s \n"HIR"#"NOR" ��ʾ������  "HIM"*"NOR" ��ʾ������"NOR,
                str, t_ppl_cnt,cnt, load);
                } else {
                str = sprintf("%s���� %d λ��������У�%d λ������,"+
                        "ƽ��ÿ��ִ�� %s ��ָ��"+
                        ((!remote&&userp(me))?"������ %s ��Դ����":"")+
                        "\n"HIR"#"NOR" ��ʾ������  "HIM"*"NOR" ��ʾ������  "CYN"��ɫ"NOR"��ʾѡ����nopk�����\n"NOR,
                        str, t_ppl_cnt, cnt,cmds, comp);
        }

        if( remote ) return str;

        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        string name1, name2;

        reset_eval_cost();
        
        name1 = ob1->query("club");
        name2 = ob2->query("club");

        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;

        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int help(object me)
{
write(@HELP

ָ���ʽ : cwho [-l|-i|-p]

���ָ������г����������ϵİ�����Ҽ���״̬��

-l ѡ���г��ϳ���ѶϢ
-i ֻ�г���ҵ�Ӣ�Ĵ���
-p ֻ�г�ͬ�ŵ����

���ָ� finger

HELP
        );
        return 1;
}

