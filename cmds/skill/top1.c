// top.c
// modify by mudring

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
#include "valid_system.h"
int top_list(object ob1,object ob2);
int get_score(object ob);
int top_level(object ob1,object ob2);
int get_level(object ob);
int main(object me, string arg)
{

        object *list, *ob,*list_level;
        int i, j, k;
        string msg;
/*
        if (arg && find_player(arg) && wizardp(me))
                me = find_player(arg);
*/
        if (! arg)
                k = 16;
        else {
        sscanf(arg, "%d", k);
        if (k < 16) k = 16;
        if (k > 50) k = 50;
        }
       if ( arg == "-l" )
        if (me->query("sen") < 80 )
                return notify_fail("��̫����,ЪЪ��.\n");
        if (!valid_system(me)) return 0;
        me->add("sen", -10);
        ob = filter_array(users(), (: userp($1) && !wizardp($1) :));

       if ( arg == "-l" )
        list = sort_array(ob, (: top_level :));
        else list = sort_array(ob, (: top_list :));

        msg ="\n                  �� "+BBLU HIW+"������"+HIR+"�߿���վ"+HIW+"�������а�"NOR" ��\n";
        msg += "�������ש����������ߩ��������������ש������������贈���������ש�����������\n";
        msg += "�����Ω�     ��        ��         ��  ��    ��  �� �ۺ����� �� �ۺϵȼ� ��\n";
        msg += "�ǩ����贈�������������������������ߩ������������ߩ����������ߩ�����������\n";
        if (k > sizeof(list)) k = sizeof(list);
        for (i = 0 ;i < k ; i++) {
                if(list[i] == me) msg += BBLU HIY;
        msg += sprintf("��"+HIR+" %-2d"NOR+" ��"+HIC+" %-14s"NOR+HIC+"%-10s"NOR+HIG+"%14s"NOR+" ��"+HIY+"%9d"NOR+" ��"+HIY+"%9d"NOR+" ��\n",
                                i+1,
                                list[i]->query("name"),
                                 "["+list[i]->query("id")+"]", list[i]->query("family")?  list[i]->query("family/family_name"):"��ͨ����",
                                 get_score(list[i]),
                                 get_level(list[i]));
        }
        if(!wizardp(me))
        {
	msg += "�ǩ�����������������������������������������������������������������������\n";

                    for( i = 0;i<sizeof(list);i++)
                    {
                    if(list[i] == me) break;
                    }
                    j = i+1;
                    msg += sprintf("��"+HIR+"  %-7s"NOR+" ��"+HIC+" %-12s"NOR+HIC+" %-10s"NOR+"��"+HIG+"%-12s"NOR+"��"+HIY+" %5d"NOR+"��"+HIY+" %5d"NOR+"  ��\n",
                    chinese_number(j),list[i]->query("name"),
                    "["+list[i]->query("id")+")",
                    list[i]->query("family")?list[i]->query("family/family_name"):"��ͨ����",
                    get_score(list[i]),
                    get_level(list[i]));

        msg += "��������������������������������������������������������������������������\n";
        msg += "  " + NATURE_D->game_time() + "�ǡ�\n";
        }
        else {
        msg += "��������������������������������������������������������������������������\n";
        msg +=  "\n "+HIW+"��Ŀǰ�ĵȼ��������ǣ�";
                   msg += sprintf("%6d%6d \n"NOR, get_score(me),get_level(me));

             }
        me->start_more(msg);
        return 1;

}
int top_list(object ob1, object ob2)
{
        int score1,score2;

        score1 = get_score(ob1);
        score2 = get_score(ob2);
        return score2 - score1;
}

int top_level(object ob1, object ob2)
{
        int score1,score2;

        score1 = get_level(ob1);
        score2 = get_level(ob2);
        return score2 - score1;
}
int get_level(object ob)
{
        int level;
         level =(int)ob->query("opinion/mete")*1000;
         level +=(int)ob->query("level")*5;
         level +=((int)ob->query("combat_exp")+(int)ob->query("doxing"))/200000;
         return level;
}

int get_score(object ob)
{
    int tlvl, i, score;
    string *ski;
    mapping skills;
    int age, exp;

    reset_eval_cost();
//    age = ob->query("mud_age") / 360;
    exp = (ob->query("daoxing") + ob->query("combat_exp")) / 2;

    skills = ob->query_skills();
    if (!sizeof(skills))
        return 1;
    ski  = keys(skills);
    for(i = 0; i<sizeof(ski); i++)
    {
        tlvl += skills[ski[i]];
    }  // count total skill levels

    score = tlvl ;
    score += ob->query("level") * 10;
//    score += ob->query("max_mana") / 10;
//    score += ob->query_str() + ob->query_int() + ob->query_spi() + ob->query_con();
    score += exp / 10000;


//    if (age > 360)
//        score += (exp / age);

    if (score < 1)
        score = 1;

    return score;
}

int help(object me)
{
write(@HELP
ָ���ʽ : top

���ָ���������֪������ʮ���������Щ����ȥ�����ǡ�
����������-l,�Ͱ��յȼ����С�

HELP
    );
    return 1;
}
