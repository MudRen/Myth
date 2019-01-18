// CMDS /cmds/std/score.c
// Created by waiwai@2000/12/21
// Update by waiwai@2001/07/07
// update by koker@2003/07/22
// ���������(Ŀǰ��Ҫ���������������õ���Ҫ�ǵ��̶�һ��Ĺ���)
// string *changed = ({ 
// "����", "����", "����", "����", "����", "�ڼ�", "����", 
// "����", "����", "�շ�", "����", "��", "����", "��ɽ"
// });
// Last modified by waiwai@2003/01/16
// Ϊ���Ǿ�������Ҫ�����޸�

#include <ansi.h>
#include <login.h>
#include <combat.h>
#include <mudlib.h>
#include <command.h>
inherit F_CLEAN_UP;

string query_time(int time);
string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor);
string transfer_string(string str, int length);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
        object ob, killer, area, mastername, sexname, npcsx;
        mapping my, quest;
        string line, temp, str, skill_type, *marks, banghui, last_fainted_from;
        object weapon;
        int i, age, attack_points, dodge_points, parry_points, quest1;
        int obstacles, office, dntg;  
        string msg, race, player, sx;
        mixed dir, file;

       seteuid(getuid(me));

        if(!arg ) ob = me;
        else if (wizardp(me) ) {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("��Ҫ�쿴˭�ĸ��˵��������\n");
        } else if( stringp(banghui=me->query("banghui"))) {
                ob =present(arg,environment(me));
                if(!ob || !ob->is_character())
                        return notify_fail("��Ҫ�쿴˭�ĸ��˵��������\n");
                if((string)ob->query("banghui")!=banghui)
                        return notify_fail("��ֻ�ܲ鿴�������ڵĸ��˵��������\n");
                } else
                return notify_fail("ֻ����ʦ��ͬ�����˲��ܲ쿴���˵ĸ��˵��������\n");

                // Added by waiwai@2002/01/16
                if( wiz_level(me) < wiz_level(ob) )
                        return notify_fail("��Ҫ�쿴˭�ĸ��˵��������\n");

        my = ob->query_entire_dbase();

        write(NOR YEL"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�"HIG"��"NOR YEL"�ԡԡ�"HIG"��"NOR YEL"�ԡԡ�"HIG
"��"NOR YEL"�ԡԡ�"HIG"��"NOR YEL"�ԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n"NOR);
        write("�����ڵ�ͷ�� : "+RANK_D->query_rank(ob)+"\n");
        write("�����ڵ�ְ�� : "+ob->short(1)+"\n");
        line = NOR YEL"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n"NOR;
        str = "";

        if( mapp(my["family"]) ) {
                if( my["family"]["master_name"] ) 
                str =my["family"]["family_name"]+WHT+my["family"]["master_name"];
        }

        if( mapp(my["marks"]) ) {
                marks = keys( my["marks"] );
                for( i = 0; i < sizeof(marks); i ++ ) {
                        if( str != "" ) str += "��";
                        str += marks[i];
                }
        }

        line += sprintf( " ���䣺[%4d]      ���գ�[%-24s]\n",
                 ob->query("age"), XYJTIME_D->check_usr_birthday(ob) ); 

        line += sprintf( " �Ա�[%-4s]      ���أ�[%-14s] ��᣺[%-8s]",
                 ob->query("gender"), chinese_number((int)ob->query_weight()/1300)+"����",
                 ob->query("club")?ob->query("club"):"δ����" );

        // Added By waiwai@2001/05/01
        if( (int)ob->query("impurity")>(int)ob->query("Fimpurity") ) 
                ob->set("Fimpurity",ob->query("impurity")); 

// Added By kuku@2003/09/06 
        if( ob->query("impurity")>0 && ob->query("impurity")<=100 ) 
                line += "   �ƶ�[С͵С��]\n"; 
        else if(ob->query("impurity")>100 && ob->query("impurity")<=200 ) 
                line += "   �ƶ�[�����ڸ�]\n"; 
        else if(ob->query("impurity")>200 && ob->query("impurity")<=300 ) 
                line += "   �ƶ�[ɱ������]\n"; 
        else if(ob->query("impurity")>300 && ob->query("impurity")<=400 ) 
                line += "   �ƶ�[ǧ����ָ]\n"; 
        else if(ob->query("impurity")>400 && ob->query("impurity")<=500 ) 
                line += "   �ƶ�[��ë��Ѫ]\n"; 
        else if(ob->query("impurity")>500 && ob->query("impurity")<=600 ) 
                line += "   �ƶ�[���׼���]\n"; 
        else if(ob->query("impurity")>600 && ob->query("impurity")<=700 ) 
                line += "   �ƶ�[�����ӯ]\n"; 
        else if(ob->query("impurity")>700 && ob->query("impurity")<=800 ) 
                line += "   �ƶ�[����]\n"; 
        else if(ob->query("impurity")<0 && ob->query("impurity")>=-100 ) 
                line += "   �ƶ�[���˺ñ�]\n"; 
        else if(ob->query("impurity")<-100 && ob->query("impurity")>=-250 ) 
                line += "   �ƶ�[һ������]\n"; 
        else if(ob->query("impurity")<-250 && ob->query("impurity")>=-625 ) 
                line += "   �ƶ�[�Ĵ�����]\n"; 
        else if(ob->query("impurity")<-625 && ob->query("impurity")>=-1562 ) 
                line += "   �ƶ�[��������]\n"; 
        else if(ob->query("impurity")<-1562 && ob->query("impurity")>=-3905 ) 
                line += "   �ƶ�[��������]\n"; 
        else if(ob->query("impurity")<-3905 && ob->query("impurity")>=-9762 ) 
                line += "   �ƶ�[�������]\n"; 
        else if(ob->query("impurity")<-9762 && ob->query("impurity")>=-24405 ) 
                line += "   �ƶ�[��˼Ȫӿ]\n"; 
        else if(ob->query("impurity")<-24405 && ob->query("impurity")>=-61012 ) 
                line += "   �ƶ�[��ȴ�]\n"; 
        else 
                line += "   �ƶ�[ ��ƽ���� ]\n"; 

        /*******************************************************************************/             
         // Added By waiwai@2001/05/01
        if(ob->query("zhongzu")){
              if(ob->query("zhongzu")=="god")
                      line +=" ���壺[����"NOR"]";
              if(ob->query("zhongzu")=="man")
                      line +=" ���壺[����"NOR"]";
              if(ob->query("zhongzu")=="ghost")
                      line +=" ���壺[ħ��"NOR"]";
        }else line+=" ���壺[����"NOR"]";

        line += sprintf( "      ְҵ��[%s%-6s%s]   ",
        HIC, ob->query("occupation")?ob->query("occupation"):"û��ע��", NOR );
        if( ob->query("club") )
         line += sprintf("    ��ְ��[%-8s]", 
                ob->query("bh_rank")?ob->query("bh_rank"):"��ͨ����");
         else
         line+= "    ��ְ��[δ����]"NOR;
        /*******************************************************************************/

        // Addded By waiwai@2001/07/07 ����������Ϣ��������
        age = (int)ob->query("life/life_time");
        age -= (int)ob->query_age() / 86400;
        msg = sprintf("[%-6s��]", chinese_number(age) );
        if( userp(ob) ) {
        if( !ob->query("life/live_forever_announced") && !ob->query("life/live_forever") ) {
        if(wizardp(me) ||
                RANK_D->grade_dx(RANK_D->describe_dx(ob->query("daoxing")))>=
                RANK_D->grade_dx(HIY"��̥����"NOR)) {
                line+= "  ���٣�"+msg+"\n";}
         else
         line+= "  ���٣�[��ʱ����]\n"NOR;
         } else  line+= "   ���٣�["RED"��������"NOR"]\n"NOR;
        } else  
        if( !userp(ob) ) { // ���Ǿ�������
        if(!age)
        line+= "  ���٣�["RED"��������"NOR"]\n"NOR;
        else
        line+= "  ���٣�["RED"+msg+"NOR"]\n"NOR;
        }

        /*******************************************************************************/
        // Addded By waiwai@2001/05/28
        if (ob->query("married")) { 
         if (ob->query("gender")=="Ů��") {
              line += sprintf(" �ɷ�[%-8s]", ob->query("couple/name"));
           } else {
              if ((int)me->query("married")<=1) {
            line += sprintf(" ���ӣ�[%-8s]", ob->query("couple/name"));
                  } else {
        if( ob->query("couple/name") && ob->query("couple2/name"))
         line += sprintf(" ���ޣ�[%-8s] С�[%-8s] ", 
        ob->query("couple/name"),ob->query("couple2/name"));
        else
        if( ob->query("couple/name") && !ob->query("couple2/name"))
         line += sprintf(" ���ޣ�[%-8s] С�[ �� �� ] ", 
        ob->query("couple/name"));
        else
        if( ob->query("couple2/name") && !ob->query("couple/name"))
         line += sprintf(" ���ޣ�[ �� �� ] С�[%-8s] ", 
        ob->query("couple/name"));
              }
        }
        } else {
           if (!ob->query("unmarryed"))
          line += " ����: [δ��]    ";
              else line += " ����: ["RED"����"NOR"]    ";
        }

           //Added By waiwai@2001/05/01
//          sexname=ob->query("couple/id");
         if ( !ob->query("sex/times") && !ob->query("sex/times2") ) {
         if (ob->query("gender")=="Ů��") line += sprintf("  ״̬��[ ��  Ů ]");
           else line += sprintf("  ״̬��[ ͯ  �� ]");
           }  else
         if ( ob->query("sex/times") && ob->query("sex/times2") ) {
//              if( ob->query("sex/firstid") == sexname )
                line += sprintf("  ״̬��["HIG"%-8s"NOR"]",ob->query("sex/first") );
           } else
        if ( !ob->query("sex/times") &&  ob->query("sex/times2") ) 
                line += sprintf("  ״̬��["HIG"%-8s"NOR"]",ob->query("sex/first") );
           else 
        if ( ob->query("sex/times") &&  !ob->query("sex/times2") ) 
                line += sprintf("  ״̬��[%-8s]",ob->query("sex/first") );
           else line += "  ״̬: [ ��  �� ]";
        mastername= ob->query("family/master_name");
        line += sprintf( "       ��Σ�[ %-2d/ %2d ]   �漮��[%s��ʿ]\n",
         ob->query("marryed"),ob->query("unmarryed"),ob->query("changed")?ob->query("changed"):WHT"����"NOR); 
        line += sprintf( " ��ְ��[%-5d]  �ٰݣ�[%s]",
         ob->query("office_number"), ob->query("degree")?ob->query("degree"):"δ����;");
        if( userp(me) && userp(ob) ) {
        if( !(string)me->query("Pfamily") ) {
        if ( mastername )
        line += sprintf( "       ʦ�У�[%-8s]\n\n ",filter_color(mastername));
              else
        line += sprintf( "       ʦ�У�[δ��ʦ��]\n\n ");
        } else
        line += sprintf( "       ʦ�У�["HIR+(string)me->query("Pfamily")+"��ͽ"NOR"] \n\n");
        } else { // ���Ǿ�������
        if( ob->query("family/family_name") )
        line += sprintf( "       ʦ�У�[%-8s]\n\n ",ob->query("family/family_name") );
        else
        line += sprintf( "       ʦ�У�[��������]\n\n ");
        }


        /*******************************************************************************/

        line += sprintf( "������[%2d/%4s %s]",
                 my["str"], display_attr(my["str"], ob->query_str()), NOR );

        if( my["eff_sen"] <my["max_sen"] ) str = HIR+"����";
        else if( my["sen"]*100 / my["max_sen"]>=70 ) str = HIG + "����";
        else if( my["sen"]*100 / my["max_sen"]>=40 ) str = HIR + "ƣ��";
        else str = HIB + "����";
        line += " ������״̬��" + tribar_graph(my["sen"], my["eff_sen"], my["max_sen"], NOR, HIR ,HIW)
                + sprintf( "  [%4s%s]  \n", str,NOR);

        line += sprintf( " ���ǣ�[%2d/%4s %s]", 
                my["con"], display_attr(my["con"], ob->query_con()), NOR );

        if( my["eff_kee"] <my["max_kee"] ) str = HIR+"����";
        else if( my["kee"]*100 / my["max_kee"]>=70 ) str = HIG + "����";
        else if( my["kee"]*100 / my["max_kee"]>=40 ) str = HIR + "�˲�";
        else str = HIB + "����";
        line += " ����Ѫ״̬��" + tribar_graph(my["kee"], my["eff_kee"], my["max_kee"],NOR, HIR ,HIW)
                + sprintf( "  [%4s%s]\n",str,NOR);

        if( my["food"] * 100 / ob->max_food_capacity() > 100 ) str = HIY+"�ٹ�";
        else if( my["food"] * 100 / ob->max_food_capacity() >= 90 ) str = HIC+"�ܱ�";
        else if( my["food"] * 100 / ob->max_food_capacity() >= 50 ) str = HIC+"����";
        else if( my["food"] * 100 / ob->max_food_capacity() >= 20 ) str = HIR+"ȱʳ";
        else str = HIB + "����";
        
        line += sprintf( " ���ԣ�[%2d/%4s %s]",
                 my["int"], display_attr(my["int"], ob->query_int()), NOR );

        line += " ��ʳ��״̬��" + tribar_graph(my["food"], ob->max_food_capacity(),
                ob->max_food_capacity(), NOR, HIC ,HIR)
                + sprintf( "  [%4s%s]\n", str, NOR );

        line += sprintf( " ���ԣ�[%2d/%4s %s]",
                my["spi"], display_attr(my["spi"], ob->query_spi()), NOR );

        if( my["water"] * 100 / ob->max_water_capacity() > 100 ) str = HIY + "�ٹ�";
        else if( my["water"] * 100 / ob->max_water_capacity() > 50 ) str = HIC + "����";
        else if( my["water"] * 100 / ob->max_water_capacity() > 30 ) str = HIR + "ȱˮ";
        else str = HIB + "����";

        line += " ����ˮ״̬��" + tribar_graph(my["water"], ob->max_water_capacity(),
                ob->max_water_capacity(), NOR, HIC ,HIR)
                + sprintf( "  [%4s%s]\n",  str, NOR );

        if(wizardp(me) ||
                RANK_D->grade_dx(RANK_D->describe_dx(ob->query("daoxing")))>=
                RANK_D->grade_dx(HIY"��̥����"NOR)) {
        line += sprintf( " ��ò��[%2d/%4s %s]", my["per"], display_attr(my["per"], ob->query_per()), NOR );
         } else
        line+=" ��ò��[ ���� ]  ";
        /*******************************************************************************/

        if(ob->query("namecolor")){
                line += " ��ƴɱ��¼��" 
                + sprintf( "ɱ����ң���[%d]��[%d] ��[%d/%d]"NOR" λ,ɱ�����ˣ�%d λ\n",  
                (int)ob->query("color_pk/common"), (int)ob->query("color_pk/yellow"), 
                (int)ob->query("color_pk/total"), my["PKS"],my["MKS"]);
        }
        else{
                line += " ��ƴɱ��¼��" 
                + sprintf( "ɱ����ң���[0]��[0] ��[%d/%d]"NOR" λ,ɱ�����ˣ�%d λ\n",  
                (int)ob->query("color_pk/total"), my["PKS"],my["MKS"]);
        }

        if(wizardp(me) ||
                RANK_D->grade_dx(RANK_D->describe_dx(ob->query("daoxing")))>=
                RANK_D->grade_dx(HIY"��̥����"NOR)) {
        line += sprintf( " ��Ե��[%2d/%4s %s]",
                my["kar"], display_attr(my["kar"], ob->query_kar()), NOR );
         } else
        line+=" ��Ե��[ ���� ]  ";

        line += " ��������¼��" 
                + sprintf( "����������%s%d%s ��,����������%s%d%s ��\n",  YEL, my["dietimes"], NOR,
                YEL, my["normal_die"], NOR);

        if(wizardp(me) ||
                RANK_D->grade_dx(RANK_D->describe_dx(ob->query("daoxing")))>=
                RANK_D->grade_dx(HIY"��̥����"NOR)) {
        line += sprintf( " ������[%2d/%4s %s]",
                my["cps"], display_attr(my["cps"], ob->query_cps()), NOR );
         } else
        line+=" ������[ ���� ]  ";

        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK); 
        parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE); 
        dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE); 

        // ������Խ����Ը���ԭ����
        if( (int)ob->query("balance")>0 )
        line+= " ��Ǯׯ��"+"/adm/daemons/moneyd.c"->money_str((int)ob->query("balance"))+"\n\n";
        else
        if( (int)ob->query("balance")<0 ) 
        line+= RED" ��ǮׯǷ�"+MONEY_D->money_str((-(int)ob->query("balance")))+"\n\n"NOR;
        else
        line+= " ��Ǯׯ��Ŀǰ�Ǹ����\n\n";
        /*******************************************************************************/
        if(wizardp(this_player())) 
        line += sprintf("\n ս�������� " HIW "%d (+%d)" NOR "\t\tս�������� " HIW "%d (+%d)\n\n" NOR,
        attack_points/100 + 1, ob->query_temp("apply/damage"),
                (dodge_points + (weapon? parry_points: 
                (parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));
        else line+=sprintf(" �����˺����� ["HIR"%d"NOR"]" NOR "\t\t���ױ������� ["HIG"%d"NOR"]\n\n" NOR,
        ob->query_temp("apply/damage"),
        ob->query_temp("apply/armor"));
        /*******************************************************************************/
        if(ob->query("quest/number"))
        line+= "��"HIG"��  ��"NOR"�������Ѿ�����"HIR+chinese_number(ob->query("quest/number"))+NOR"����\n";
        else line+="��"HIG"��  ��"NOR"����"+HIR"�㻹û�н���"NOR+"\n";
        obstacles = ob->query("obstacle/number");
        if(obstacles)
        line += sprintf(RED" ����ȡ��"NOR"�����Ѿ�����"RED"%s"NOR"�����ѡ�\n", chinese_number(obstacles));
        else line += RED" ����ȡ��"NOR"���㻹δ��̤��ȡ��֮·\n";
        dntg = ob->query("dntg/number");
        if (dntg == 0) line += " "RED"�����칬"NOR"���㻹δ�������칬\n";
        else line+= RED" �����칬"NOR"��������칬�ѹ�"HIR+chinese_number(dntg)+NOR"�ء�\n";
        if (ob->query("die_reason"))  
        line +=sprintf(RED" �ϴ�����"NOR"��%s\n\n", ob->query("die_reason")); 

        /*******************************************************************************/        
        if(ob->query("BHPJ")<0) ob->set("BHPJ",0);

        line += sprintf(" ���������ȣ� "YEL"%5d   " NOR "     ����ҳ϶ȣ� "YEL"%4d / %4d"NOR"        �������ֵ�� "YEL"%5d \n"NOR,
        ob->query("MP_killM"), ob->query("zhongcheng"), ob->query("max_zhongcheng"), ob->query("BHPJ"));

        line += sprintf(" �����ҳ϶ȣ� "YEL"%5d   " NOR "     �ɷ�������� "YEL"%4d / %4d"NOR"        Ǳ�ܴ������� "YEL"%5d \n\n"NOR,
           (int)ob->query("faith"), ob->query("gift_points"), 
        ob->query("used_gift_points"), (int)ob->query("qn_balance"));

        /*******************************************************************************/
        //Added By waiwai@2001/05/01
        if( !ob->query("killtocity"))  ob->set("killtocity","��������");

        if( ob->query("killtoname") && ob->query("killtoid") )
        line+=sprintf(" �ϴ�ɱ¾��[%s] ��"YEL"%s(%s)"NOR"ɱ����%s \n",
                ob->query("killtotime"), ob->query("killtoname"),
                ob->query("killtoid"), ob->query("killtocity"));
              else
        if( !ob->query("killtoname")) line+= "\n";

        //Added By waiwai@2001/05/01
        if( !ob->query("killbycity"))  ob->set("killbycity","��������");

        if( ob->query("killbyname") && ob->query("killbytime") && ob->query("killbyname")!="������"){
        line+=sprintf(" �ϴ�����[%s] ��"YEL"%s(%s)"RED"%s"NOR"������%s\n",
                ob->query("killbytime"), ob->query("killbyname"),ob->query("killbyid"),
                ob->query("killbyB")?ob->query("killbyB"):"", ob->query("killbycity"));
              } else
        if( ob->query("killbyname") && ob->query("killbyname")!="������"){
                line+= " �ϴ�������"YEL+ob->query("killbyname")+"("+ob->query("killbyid")+")"RED+
(ob->query("killbyB")?ob->query("killbyB"):"")+NOR"������"+ob->query("killbycity")+" ʱ�䲻�� \n";
          }
        if( ob->query("killbyname") && ob->query("killbytime") && ob->query("killbyname")=="������"){
        line+=sprintf(" �ϴ����� [%s] ������ ������%s\n",ob->query("killbytime"),  ob->query("killbycity"));
              } else
        if( ob->query("killbyname") && ob->query("killbyname")=="������"){
                 line+= "�ϴ�����"YEL"������ ʱ�䲻�� "NOR"��"+ob->query("killbycity")+"\n"NOR;
          } 

        if( !ob->query("killbyname")) line+= "\n";
        /*******************************************************************************/

        if(ob->query("kill/pkgain") ) { 
                line +=sprintf(NOR" �У˵��У�%s  \n", XYJTIME_D->check_daoxing(ob->query("kill/pkgain")));
                if(!ob->query("kill/pklose") && !ob->query("kill/nkgain") ) line+="\n";
        }

        if(ob->query("kill/nkgain") ) 
                line +=sprintf(NOR" �Σ˵��У�%s\n\n", XYJTIME_D->check_daoxing(ob->query("kill/nkgain")));
        else   line +="\n";
        /*******************************************************************************/

        line += sprintf(" ���о��磺%s ��ѧ���磺%s ������Ϊ��%s ������Ϊ��%s\n",
                 RANK_D->describe_dx(ob->query("daoxing")),  RANK_D->describe_exp(ob->query("combat_exp")), 
                 RANK_D->describe_fali(ob->query("max_mana")),RANK_D->describe_neili(ob->query("max_force")));

        line += YEL"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ� "HIG+INTERMUD_NAME+NOR+YEL" �ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n"NOR;
        if( userp(me) && userp(ob) ) {
        line += sprintf("��������%s�Ѿ����� "YEL"%s"NOR" ������ "NOR,
        ob==me?"��":ob->name(1),FINGER_D->age_string( (int)ob->query("mud_age")) );
        line += sprintf("��������%s��ͣ��ʱ��Ϊ "YEL"%s \n"NOR,
              ob==me?"��":ob->name(1),FINGER_D->age_string(time()-ob->query_temp("logon_time")) );
        }

        write(line);
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

string transfer_string(string str, int length)
{
        string str1, str2, tmp;
        int i;

        tmp=str;
        while(sscanf(str,"%s*sm%s",str1,str2)==3)
                str=str1+str2;
        i=length-strlen(str);
        while(i>0)
        {
                tmp+=" ";
                i--;
        }
        return tmp;
}

string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor)
{
        string ret;
        int i, n, eff_n, max_n = 10;

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

ָ���ʽ��score/sc
          score <��������>  ����ʦר�ã�

��ʾ�Լ�����ָ�����󣨺�����Ļ������ϡ�
��ָ����ԡ�sc�����档

�������ز���ֻ�е�����дﵽ��̥����ʱ��
���Կ���������

���ѶϢ��hp

HELP
        );

        return 1;
}
