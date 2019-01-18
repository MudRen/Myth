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
                 int birthday;
        string line, str, skill_type, *marks;
        object weapon;
        int i, attack_points, dodge_points, parry_points,obstacles,quest1,dntg;

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
        write(NOR YEL"�ԡԡԡԡԡԡԡԡԡԡԡԡ�"HIG"��"NOR YEL"�ԡԡ�"HIG"��"NOR YEL"�ԡԡ�"HIG"��"NOR YEL"�ԡԡ�"HIG"��"NOR YEL"�ԡԡԡԡԡԡԡԡԡԡԡԡ�\n"NOR);
        write("�����ڵ����� : "+RANK_D->query_rank(ob)+"\n");
        write("�����ڵ�ְ�� : "+ob->short(1)+"\n");
      if(ob->query("hell_type")) 
        write("�����ڵĽ�ɫ : "+ob->query("hell_type")+"\n"); 
         else         write("�����ڵĽ�ɫ : ��ͨũ��\n"); 
        line = NOR YEL"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n"NOR;
        str = "";
        if( mapp(my["family"]) ) {
                if( my["family"]["master_name"] ) str =my["family"]["family_name"]+HIC+my["family"]["master_name"];
        }
        if( mapp(my["marks"]) ) {
                marks = keys( my["marks"] );
                for( i = 0; i < sizeof(marks); i ++ ) {
                        if( str != "" ) str += "��";
                        str += marks[i];
                }
        }

        birthday=(int)ob->query("birthday");
        line += sprintf( " ���䣺[%s%-4s%s]     ���գ�[%s%-24s%s]\n",
                 HIC, chinese_number(ob->query("age")), NOR,
               HIC, CHINESE_D->chinese_date(birthday), NOR );

        line += sprintf( " �Ա�[%s%-4s%s]     ���أ�[%s%-4s����%s]  ��᣺[%s%-6s%s]\n",
                 HIC, ob->query("gender"), NOR,
                 HIC, chinese_number((int)ob->query_weight()/1000), NOR,
                 HIC, ob->query("club")?ob->query("club"):"δ�뽭��", NOR );

if (ob->query("couple/name") != 0) line += sprintf(" ����״����" HIG"���£�%-11s"NOR,ob->query("couple/name"));
        else line += sprintf(" ����״����" MAG"δ��\t\t\t"NOR);
        if( str != "" ) line += sprintf( " ʦ�У�[%-20s%s]\n",str, NOR );
        else line+=" ʦ�У�"+"["CYN"��δ����ʦѧ��"NOR"]\n";    
        
        line += sprintf( " ��ְ��[%s%6-d]  ",
                NOR, (int)ob->query("office_number"));
      if (ob->query("degree"))
        line+= "��"WHT"�ٰ�"NOR"����["+ob->query("degree")+"]\n";
        else line+="��"WHT"�ٰ�"NOR"����"+NOR"["HIC"��"NOR"    ]"NOR+"\n";
        
        if( objectp(weapon = ob->query_temp("weapon")) )
                skill_type = weapon->query("skill_type");
        else
                skill_type = "unarmed";

       attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
        parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
        dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

       line += sprintf( " ���[%s %4s %s]  ",
                 NOR, display_attr(my["str"], ob->query_str()), NOR );
        if( my["eff_sen"] <my["max_sen"] ) str = HIR+"����";
        else if( my["sen"]*100 / my["max_sen"]>=70 ) str = HIG + "����";
        else if( my["sen"]*100 / my["max_sen"]>=40 ) str = HIR + "ƣ��";
        else str = HIB + "����";
        line += "��"HIR"����"NOR"��  " + tribar_graph(my["sen"], my["eff_sen"], my["max_sen"], NOR, HIR ,HIW)
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
        line += sprintf( " ��ò��[%s %4s %s]  ",
                NOR,display_attr(my["per"], ob->query_per()), NOR );
        else line+=" ��ò��[ ���� ]  ";
        
        line += "��"HIW"����"NOR"����" 
                + sprintf( "ɱ����ң�%s%d%s λ,ɱ�����ˣ�%s%d%s ��,��ɱ����%s%d%s ��\n",  HIR, my["PKS"], NOR,
                HIW, my["MKS"], NOR,HIR, my["DIE"], NOR,);
 
  
         if(ob->query("age")>25)
        line += sprintf( " ��Ե��[%s %4s %s]  ",
                NOR, display_attr(my["kar"], ob->query_kar()), NOR );
        else line+=" ��Ե��[ ���� ]  ";
        if((int)ob->query("balance"))
        line+= "��"HIY"���"NOR"����"+"/adm/daemons/moneyd.c"->money_str((int)ob->query("balance"))+"\n";
        else line+="��"HIY"���"NOR"����"+HIW"û���κδ��"NOR+"\n";
        
                if(ob->query("age")>30)
                     line += sprintf( " ������[%s %4s %s]  ",
                NOR, display_attr(my["cps"], ob->query_kar()), NOR );
                          else line+=" ������[ ���� ]  ";
              if(ob->query("quest/number"))
        line+= "��"HIG"����"NOR"�������Ѿ�����"HIR+chinese_number(ob->query("quest/number"))+NOR"����\n\n";
        else line+="��"HIG"����"NOR"����"+HIR"�㻹û�н���"NOR+"\n\n";

         line += sprintf( " ְҵ��[%s%-6s%s]   ",
                 HIC, ob->query("zhiye")?ob->query("zhiye"):"���ֺ���", NOR );
              if(ob->query("age")>25)
        line+= " ���٣�[  "RED+(int)ob->query("life/life_time")+NOR+"  ]   ";
        else line+=" ���٣�[ ���� ]   ";

              if(ob->query("age")>25)
        line+= " �˲ι���[  "HIR+(int)ob->query("rsg_eaten")+NOR+"  ]\n";
        else line+=" �˲ι���[ ���� ]\n";


     if(wizardp(this_player())) 
        line += sprintf("\n ս�������� " HIW "%d (+%d)" NOR "\t\tս�������� " HIW "%d (+%d)\n\n" NOR,
        attack_points/100 + 1, ob->query_temp("apply/damage"),
                (dodge_points + (weapon? parry_points: 
                (parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));
        else line+=sprintf(" �����˺����� ["HIR"%d"NOR"]" NOR "\t\t���ױ������� ["HIG"%d"NOR"]\n\n" NOR,
        ob->query_temp("apply/damage"),
        ob->query_temp("apply/armor"));
        line+= "��"HIC"��������"NOR"����"+HIR""+(int)ob->query("weiwang")+NOR+"\t\t\t��"HIC"�����ҳ϶�"NOR"��"+HIR""+(int)ob->query("faith")+NOR+"\n\n";
obstacles = ob->query("obstacle/number");
        if(obstacles)
                line += sprintf(RED" ����ȡ��"NOR"�����Ѿ�����"RED"%s"NOR"�����ѡ�\n", chinese_number(obstacles));
                else line += RED" ����ȡ��"NOR"���㻹δ��̤��ȡ��֮·\n";
        dntg = ob->query("dntg/number");
             if (dntg == 0) line += " "RED"�����칬"NOR"���㻹δ�������칬\n";
             else line+= RED" �����칬"NOR"��������칬�ѹ�"HIR+chinese_number(dntg)+NOR"�ء�\n";
        if (ob->query("die_reason"))
                line +=sprintf(RED" �ϴ�����"NOR"��%s\n", ob->query("die_reason"));
        if(ob->query("kill/pkgain") ) 
        { 
                line +=sprintf(" �У˵������ӣ� %s  \n", COMBAT_D->chinese_daoxing(ob->query("kill/pkgain")));
                if(!ob->query("kill/pklose") && !ob->query("kill/nkgain") ) line+="\n";
        }
        if(ob->query("kill/nkgain") ) 
        {
                line +=sprintf(" �Σ˵������ӣ� %s\n", COMBAT_D->chinese_daoxing(ob->query("kill/nkgain")));
        }

        line += sprintf(" ���о��磺[%s]       ��ѧ���磺[%s]\n",
                 RANK_D->describe_dx(ob->query("daoxing")),  RANK_D->describe_exp(ob->query("combat_exp")) );
        line += sprintf(" ������Ϊ��[%s]       ������Ϊ��[%s]\n",
                 RANK_D->describe_fali(ob->query("max_mana")),  RANK_D->describe_neili(ob->query("max_force")) );
        line += YEL"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n"NOR;
line += sprintf(WHT+" Ϊ��ȡ�澭%s�Ѿ�����"HIR"%s"NOR"������ \n\n"+NOR,ob==me?"��":ob->name(1),CHINESE_D->chinese_time( (int)ob->query("mud_age")));

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

