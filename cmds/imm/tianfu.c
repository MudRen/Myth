// gift.c
// 8-13-97 pickle
 
#include <ansi.h>

inherit F_CLEAN_UP;

string *gift_ranking = ({"����","�µ�", "����", "�е�", "����", "�ϵ�", "����"});

string display_attr(string gift, int value,int effective);
string type;

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
    mapping my;
    string line, player_id, flag;
    int i;
    object player;
       if (me != this_player()) return 0;
     if (! SECURITY_D->valid_grant(me, "(immortal)")) return 0;
 
    seteuid(getuid(me));

    if (!arg) player=me;
    else if(sscanf(arg, "-%s %s", flag, player_id) != 2)
    {
        if (!flag)
        {
	type="current";
	player_id=arg;
        }
        else if (flag != "o") return notify_fail ("����� help gift��\n");
        type="original";
        player_id=this_player()->query("id");
    }
    else
    {
        if (flag !="o") return notify_fail ("����� help gift��\n");
        type="original";
    }
    if (!player) player = present(player_id, environment(me));
    if (!player) player = find_player(arg);
    if (!player) player = find_living(arg);
    if (!player) return notify_fail("��Ҫ�쿴˭��״̬��\n");
    my = player->query_entire_dbase();
    line = sprintf(
            " ������[%s]  ��ʶ��[%s]  ���ԣ�[%s]  ���ԣ�[%s]\n"
            " ������[%s]  ��ò��[%s]  ���ǣ�[%s]  ��Ե��[%s]\n\n",
            display_attr("str", my["str"], player->query_str()),
            display_attr("cor", my["cor"], player->query_cor()),
            display_attr("int", my["int"], player->query_int()),
            display_attr("spi", my["spi"], player->query_spi()),
            display_attr("cps", my["cps"], player->query_cps()),
            display_attr("per", my["per"], player->query_per()),
            display_attr("con", my["con"], player->query_con()),
            display_attr("kar", my["kar"], player->query_kar()));

/*            my["str"], my["cor"], my["int"], my["spi"],
            my["cps"], my["per"], my["con"], my["kar"]);
 
            gift_evaluation(my["str"]), gift_evaluation(my["cor"]),
            gift_evaluation(my["int"]), gift_evaluation(my["spi"]),
            gift_evaluation(my["cps"]), gift_evaluation(my["per"]),
            gift_evaluation(my["con"]), gift_evaluation(my["kar"]));
*/
    line += sprintf(" �ۺ����ۣ� " HIC "%d\n\n" NOR,player->query("score") );
 
    write(line);
    return 1;
}

string display_attr(string gift, int value, int effective)
{
    int eff_value=value, eval_value;
    string eval="��";
    if (type=="current") eff_value=effective;
    eval_value=eff_value;
    if (eval_value > 21) eval_value-=1;
    eval_value-=10;
    if (eval_value<0) eval_value=0;
    if (eval_value>20) eval_value=20;
    eval+=gift_ranking[eval_value/4];
    if( eff_value > value ) return sprintf( HIY "%3d" NOR+eval, value );
    else if (eff_value < value) return sprintf( CYN "%3d" NOR+eval, value );
    else return sprintf("%3d"+eval, value);
}

int help(object me)
{
    write(@HELP
ָ���ʽ��gift [-o] <��������>
 
���ָ�������ʾ���ָ�����󣨺�������츳��

-o (original) ��ʾ����츳������literate�ȵ�Ч������
see also : score
HELP
    );
    return 1;
}
