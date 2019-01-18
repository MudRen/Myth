// score.c



#include <ansi.h>
#include <combat.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
        object ob;
        mapping my;
        string line, str, skill_type, *marks,*hskill,*nskill;
        object weapon;
        int i, attack_points, dodge_points, parry_points;
        hskill=({"sword", "blade","hammer","staff","whip","axe",
                 "fork","spear","mace","stick","unarmed","dodge",});
        nskill=({"����","����","�󴸷�","ħ����","����","����","����","ǹ��","ﵷ�",
                "����","ȭ����","������",});

        seteuid(getuid(me));
        if(!arg)
                ob = me;
        else if (wizardp(me)) {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
        } else
                return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

        my = ob->query_entire_dbase();
        write(NOR YEL"�ԡԡԡԡԡԡԡԡ�"HIG"��"NOR YEL"�ԡ�"HIG"��"NOR YEL"�ԡ�"HIG"��"NOR YEL"�ԡ�"HIG"��"NOR YEL"�ԡ�"HIG"��"NOR YEL"�ԡԡԡԡԡԡԡԡ�\n"NOR);
        write("�����ڵ����� : "+RANK_D->query_rank(ob)+"\n");
        write("�����ڵ�ְ�� : "+ob->short(1)+"\n");
        if(ob->query("hell_type"))     write("�����ڵĽ�ɫ : "+HIR+ ob->query("hell_type")+NOR+"\n");  
                                  else write("�����ڵĽ�ɫ : ��ͨũ��\n");  
 
        line = NOR YEL"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n"NOR;
        str = "";
 


        
      
        if( objectp(weapon = ob->query_temp("weapon")) )
                skill_type = weapon->query("skill_type");
        else
                skill_type = "unarmed";

       attack_points = CITY_D->hell_skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
        parry_points = CITY_D->hell_skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
        dodge_points = CITY_D->hell_skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

       line += sprintf( " ���[%s %4s %s]  ",
                 NOR, display_attr(my["str"], ob->query_str()), NOR );
        if( my["eff_gin"] <my["max_gin"] ) str = HIR+"����";
        else if( my["gin"]*100 / my["max_gin"]>=70 ) str = HIG + "����";
        else if( my["gin"]*100 / my["max_gin"]>=40 ) str = HIR + "ƣ��";
        else str = HIB + "����";
        line += "��"HIR"����"NOR"��  " + tribar_graph(my["gin"], my["eff_gin"], my["max_gin"], NOR, HIR ,HIW)
                + sprintf( "  [%4s%s]\n", str,NOR);
        line += sprintf( " ���ǣ�[%s %4s %s]  ",
                NOR, display_attr(my["con"], ob->query_con()), NOR );
        if( my["eff_kee"] <my["max_kee"] ) str = HIR+"�˲�";
        else if( my["kee"]*100 / my["max_kee"]>=70 ) str = HIG + "����";
        else if( my["kee"]*100 / my["max_kee"]>=40 ) str = HIR + "����";
        else str = HIB + "����";
        line += "��"HIR"��Ѫ"NOR"��  " + tribar_graph(my["kee"], my["eff_kee"], my["max_kee"], NOR, HIR ,HIW)
                + sprintf( "  [%4s%s]\n",str,NOR);
        
        
        
        

        if( my["food"] * 100 / ob->max_food_capacity() >= 80 ) str = HIG+"�ܱ�";
        else if( my["food"] * 100 / ob->max_food_capacity() >= 50 ) str = HIC+"����";
        else if( my["food"] * 100 / ob->max_food_capacity() >= 20 ) str = HIR+"ȱʳ";
        else str = HIB + "����";
        
        

        if( my["water"] * 100 / ob->max_water_capacity() > 60 ) str = HIG + "����";
        else if( my["water"] * 100 / ob->max_water_capacity() > 30 ) str = HIR + "ȱˮ";
        else str = HIB + "����";
        line += sprintf( " ���ԣ�[%s %4s %s]  ",
                NOR, display_attr(my["int"], ob->query_int()), NOR );
        line += "��"HIC"ʳ��"NOR"����" + tribar_graph(my["food"], ob->max_food_capacity(),
                ob->max_food_capacity(), NOR, HIC ,HIR)
                + sprintf( "  [%4s%s]\n", str, NOR );        
        line += sprintf( " ���ԣ�[%s %4s %s]  ",
                NOR, display_attr(my["spi"], ob->query_spi()), NOR );
        line += "��"HIC"��ˮ"NOR"����" + tribar_graph(my["water"], ob->max_water_capacity(),
                ob->max_water_capacity(), NOR, HIC ,HIR)
                + sprintf( "  [%4s%s]\n",  str, NOR );
              if(ob->query("age")>25)

      
        line += sprintf(NOR CYN"��������������������������������HELLFIRE������������������������������\n" NOR);
        line += sprintf(NOR CYN"��"NOR WHT"�� ���������� ��%s%14-d " NOR "     "WHT"�� ������ ��%s%4d "NOR"      "CYN" �� "NOR"\n" NOR,
                  HIY,my["hell_pot"],HIW,my["hell_exp"]);

        line +=  sprintf(NOR CYN"��"NOR WHT"�� ħ���� ��   %s%16-d " NOR "     "WHT"�� ħ���ȼ� ��%s%4d "NOR"     "CYN" �� "NOR"\n" NOR,
                  HIY,my["magic_pointed"],HIW,my["magiclevel"]);
        line += sprintf(NOR CYN"������������������������������"HIY"S"HIR"��"HIY"J"HIR"��"HIY"S"HIR"��"HIY"H"NOR CYN"����������������������������\n"NOR);
        


     if(wizardp(this_player())) 
        line += sprintf("\n ս�������� " HIW "%d (+%d)" NOR "\t\tս�������� " HIW "%d (+%d)\n\n" NOR,
        attack_points/100 + 1, ob->query_temp("apply/damage"),
                (dodge_points + (weapon? parry_points: 
                (parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));
        else line+=sprintf(" �����˺����� ["HIR"%d"NOR"]" NOR "\t\t���ױ������� ["HIG"%d"NOR"]\n\n" NOR,
        ob->query_temp("apply/damage"),
        ob->query_temp("apply/armor"));
     line +="�������ɫ����:\n";
        for(i=0;i<sizeof(hskill);i++)
        {       
        
        line +=sprintf("%s %10-s %18-d  "NOR,"��"+HIC+nskill[i]+NOR+"��","("+hskill[i]+")",ob->query("hell_skill/"+hskill[i]));
        if (i-((i/2)*2)==1) line+="\n";
        }
        line+="\n";
        line += YEL"�ԡԡԡԡԡԡԡԡԡ� "HIR"������"HIY"��"HIG"�߿�վ"NOR YEL" �ԡԡԡԡԡԡԡԡԡԡ�\n"NOR;

        write(line+BBLK);
        return 1;
}


string display_attr(int gift, int value)
{
        if( value > gift ) return sprintf( HIY "%4d", value );
        else if( value < gift ) return sprintf( HIC "%4d", value );
        else return sprintf("%3d", value);
}

string status_color(int current, int max)
{
        int percent;

        if( max ) percent = current * 100 / max;
        else percent = 100;

        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}

string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor)
{
        string ret;
        int i, n, eff_n, max_n = 12;

        if( max == 0 ) max = 1;
        n = val * 100 / max / 10;
        eff_n = eff * 100 / max / 10;

        if( n < 0 ) n = 0;
        if( eff_n < 0 ) eff_n = 0;
        if( n > max_n ) n = max_n;
        if( eff_n > max_n ) eff_n = max_n;

        ret = NOR  + bcolor + fcolor ;
        for( i = 0 ; i < max_n; i ++ ) {
                if( i > eff_n ) ret += dcolor;
                if( i < n )  ret += "��";
                else ret += HIW"��"NOR;
        }
        ret += fcolor + NOR ;
        return ret;
}
int help(object me)
{
        write(@HELP
ָ���ʽ��score
          score <��������>      ����ʦר�ã�

��ʾ�Լ�����ָ�����󣨺�����Ļ������ϡ���ָ����ԡ�sc�����档

���ѶϢ��hp
HELP
        );

        return 1;
}


