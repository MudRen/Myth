// the wizard part modified by vikee for xlqy
// look.c
 // "per" parts modified by none at 96/10/02

#pragma save_binary
#include <room.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string do_query(object obj);
// mon 6/6/98
string *peep_msg = ({
        "��������̽ͷ̽�Ե�����������˼��ۡ�\n",
        "$N̽ͷ̽�Ե�����������˼��ۡ�\n",
        "���Ȼ�����ƺ���˫�۾��ڱ������㿴��\n",
        });

string *look_level_boy = ({
 BLU "ü����б����ͷѢ�ţ���������\n" NOR,
 BLU "�������죬������ף�����ޱ�\n" NOR,
 BLU "�����Ƥ��ͷ���������˲����ٿ��ڶ���\n" NOR,
 HIB "��ü���ۣ�������ߣ�������״\n" NOR,
 HIB "��ͷ�������Բ��ģ��ֽŶ̴֣����˷�Ц\n" NOR,
 NOR "��հ��ݣ��ݹ����꣬������̾\n" NOR,
 NOR "ɵͷɵ�ԣ��ճպ�����������Ҳ��ʵ\n" NOR,
 NOR "��òƽƽ�������������ʲôӡ��\n" NOR,
 YEL "�����Բ���������⣬���ζ���\n" NOR,
 YEL "��Բ���������ڷ����Ǹ񲻷�\n" NOR,
 RED "üĿ���㣬�����󷽣�һ���˲�\n" NOR,
 RED "˫�۹⻪Ө��͸���������ǵĹ�â\n" NOR,
 HIY "�ٶ���������ˮ�����̷��飬������������Ŀ��\n" NOR,
 HIY "˫Ŀ���ǣ�ü�Ҵ��飬�������޲�Ϊ֮�Ķ�\n" NOR,
 HIR "�����촽�����˿��Σ���ֹ��������\n" NOR,
 HIR "��������Ŀ�����ǣ����˹�Ŀ����\n" NOR,
 MAG "�������񣬷�ױ��������������\n" NOR,
 MAG "Ʈ�ݳ�������������\n" NOR,
 MAG "�����ʣ��������������������ٷ�\n" NOR,
 HIM "������ˬ���Ǹ����棬��������\n" NOR,
 HIM "һ���������ȣ��ɷ���ǣ���ֹ����\n" NOR,
});

string *look_level_girl = ({
  BLU "�������Σ�״��ҹ��\n" NOR,
  BLU "���б�ۣ���ɫ�Ұܣ�ֱ����һ��\n" NOR,
  BLU "����ü�������ۣ���Ƥ�Ʒ�������һ��������\n" NOR,
  HIB "��С�綹��üëϡ�裬�����צ����������\n" NOR,
  HIB "һ�����������һ����û�ø�\n" NOR,
  NOR "�������Ƥɫ�ֺڣ���ª����\n" NOR,
  NOR "�ɻƿ��ݣ���ɫ���ƣ�����Ů��ζ\n" NOR,
  YEL "�����С�������޹⣬��������\n" NOR,
  YEL "�䲻���£���Ҳ�׾�����Щ����֮��\n" NOR,
  RED "����΢�ᣬ�ŵ��������¿���\n" NOR,
  RED "�������ģ�����Ө͸��������˼\n" NOR,
  HIR "��С���磬���������������������\n" NOR,
  HIR "�������󣬼���ʤѩ��Ŀ����ˮ" NOR,
  HIW "���۰���������ҩ���̣����￴��\n" NOR,
  HIW "����ϸ������欶��ˣ�����һ������������\n" NOR,
  MAG "�����������������£�����ܳ�������\n" NOR,
  MAG "üĿ�续������ʤѩ�����ν�����߻�\n" NOR,
  MAG "�������������Ż���ɽ�����˼�֮����\n" NOR,
  HIM "������ϼ���������񣬻�����������\n" NOR,
  HIM "�������ɣ���մһ˿�̳�" NOR,
  HIM "����"HIW"������"HIM"�������ƻã��Ѳ����Ƿ�������\n" NOR,
});

string *per_msg_kid1 = ({
        CYN "��ü���ۣ�����ʮ�㡣\n" NOR,
        CYN "������ã���̬�Ƿ���\n" NOR,
        CYN "�������£�ɫ��������\n" NOR,
});

string *per_msg_kid2 = ({
        CYN "¡����ۣ���ɫ����\n" NOR,
        CYN "�����ལ�����ϲ����\n" NOR,
        CYN "ϸƤ���⣬�ڳ�������\n" NOR,
});

string *per_msg_kid3 = ({
        CYN "����󰫣�ɵ��ɵ����\n" NOR,
        CYN "�ʷ����֣�С��С�ۡ�\n" NOR,
        CYN "��ͷ���ԣ����ֱ��š�\n" NOR,
});

string *per_msg_kid4 = ({
        CYN "��ͷ���ţ����Ƽ��ݡ�\n" NOR,
        CYN "����ľ�������в�ɫ��\n" NOR,
        CYN "��ٲ�������֫���ࡣ\n" NOR,
});
mapping look_exits = ([
        "north":                "����",
        "south":                "�ϱ�",
        "east":                 "����",
        "west":                 "����",
        "northup":              "����",
        "southup":              "�ϱ�",
        "eastup":               "����",
        "westup":               "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":             "����",
        "westdown":             "����",
        "northeast":    "������",
        "northwest":    "������",
        "southeast":    "���Ͻ�",
        "southwest":    "���Ͻ�",
        "up":                   "�м�",
        "down":                 "�м�",
        "out":                  "�м�",
        "enter":                "�м�",
        "left":                 "����",
        "right":                "����",
]);

// snowcat 12/20/97
string ride_suffix (object me)
{
  string ridemsg = 0;
  object ridee = 0;

  ridee = me->ride();
  if (ridee)
    ridemsg = ridee->query("ride/msg")+"��"+ridee->name()+"��";
  return ridemsg;
}
string check_position(object obj,object env)
{ 
        string str,*flor,*mid,*upon;
        int n,xx,yy,zz,pos;
        
        str="";
flor=({"������","�ڵ���",});
mid =({"���ڿ���","������ߵ�","Ʈ���ڿ���","�����ڿ���",});    
upon=({"ճ�ڶ�����","�����ڶ�����","�����ڶ�����","�����ڶ����"});
        if(!obj->query_temp("position"))
                return "<�޷�λ��>";
        
        xx=obj->query_temp("position/xx");
        yy=obj->query_temp("position/yy");
        zz=obj->query_temp("position/zz");
        pos=env->query("position_max");
        if(! pos && (pos <2 || pos >8) ) pos =3;
        switch (zz)
               {
                case 0:
                 str=flor[random(sizeof(flor))];
                 break;
                case 1:
                 str="<"+mid[random(sizeof(mid))]+">";
                 return str;
                 break;
                case 2:
                str=upon[random(sizeof(upon))];
                break;
                }
/*
     switch (xx,yy){
                case (n+pos,n+pos):
                       str="<"+ str+ "�Ķ��Ͻ���>";
                       break;
                  default str ="<"+str ">";
                }
*/
                return str;

}
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;

        if( !arg ) result = look_room(me, environment(me));
        else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
                if( obj->is_character() ) result = look_living(me, obj);
                else result = look_item(me, obj);
        } else result = look_room_item(me, arg);

        return result;
}

int look_room(object me, object env)
{
        int i;
        object *inv;
        mapping exits;
        string str, str1="", str2="", *dirs;
        string ridemsg = "";

        if( !env ) {
                write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
                return 1;
        }
          str = sprintf( "%s  %s\n    %s%s",
     env->query("short")?(env->query("outdoors")?HIR"��"HIG+(string)env->query("short")+HIR"��"NOR:HIR"��"HIY+(string)env->query("short")+HIR"��"NOR): "",
//137       wizardp(me)?WHT+" - "+file_name(env)+NOR: "",  // by mudring@sjsh
     wizardp(me)? WHT+file_name(env)+sprintf(" - (%d,%d,%d)",env->query("coor/x"),env->query("coor/y"),env->query("coor/z"))+NOR: "",
     env->query("long")? env->query("long"): "\n",
     env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

        if( mapp(exits = env->query("exits")) ) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
                        {
                                if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                    {dirs[i] = 0;continue;}
                                if(env->query("hellfireroom"))
                                    {
                                        if( undefinedp(look_exits[dirs[i]]) )
                                        dirs[i] = dirs[i]+"<�м�>";
                                        else dirs[i]=dirs[i]+"<"+look_exits[dirs[i]]+">";
                                    }
                         }           
                dirs -= ({ 0 });
                if (env->query("no_look") && !wizardp(me))
                        str += "    ����ĳ�·���������\n";
                else if( sizeof(dirs)==0 )
                        str += "    ����û���κ����Եĳ�·��\n";
                else if( sizeof(dirs)==1 ) {
                         str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0]+ NOR;
                        if (env->query("no_look"))
                                str += "<������>";
                        str += "��\n";

                } else {
                        str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR,
                                implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
                        if (env->query("no_look"))
                                str += " <������>";
                        str += "��\n";
                }
        }
//      str += env->door_description();

        inv = all_inventory(env);
        i=sizeof(inv);
        str2 = "";
        while(i--) {
                str1 = "";
                if( !me->visible(inv[i]) ) continue;
                if( inv[i]==me ) continue;
                if (env->query("no_look"))
                {
                        str1 += "  " + "ģ����Ӱ��";
                        if (! wizardp(me))
                        {
                                str1 += "\n";
                                str += str1;
                                continue;
                        }
                }
                if (ridemsg = ride_suffix(inv[i]))
                        str1 += "  " + inv[i]->short() + " <"+ridemsg +
                          ">";
                else
                        str1 += "  " + inv[i]->short();
                if(env->query("hellfireroom"))
                str1= sprintf("%12s   %s",check_position(inv[i],env),str1);
                
                if (env->query("no_look"))
                        str1 += " <������>";
                str1 += "\n";
                str2 = str1 + str2;
        }
        write(str+str2);

        return 1;
}

int look_item(object me, object obj)
{
        mixed *inv;

//      write(obj->long());
        me->start_more(obj->long());

        //added by weiqi for self-made fabao
        if( obj->query("series_no") && obj->query("fabao") )
            write(obj->show_status());
        if(obj->query("weapon_prop"))
            write(WEAPON_D->get_look_msg(obj));

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object() );
                message("vision", sprintf("�����У�\n  %s\n",
                        implode(inv, "\n  ") ), me);
        }
        return 1;
}
string per_status_msg(int age, int per, string gender)
{
        // added by snowcat
        if (age < 14) {
                if ( per>=25 )
                        return ( per_msg_kid1[random(sizeof(per_msg_kid1))]);
                else if ( per>=20 )
                        return ( per_msg_kid2[random(sizeof(per_msg_kid2))]);
                else if ( per>=15 )
                        return ( per_msg_kid3[random(sizeof(per_msg_kid3))]);
                else    return ( per_msg_kid4[random(sizeof(per_msg_kid4))]);
                }

        if ( gender == "����" ) {
                if ( per>=10&&per<=30 )
                        return ( look_level_boy[per-10]);
                else if (per>30)
                       return ( look_level_boy[20]);
                else return "����������ûʲô���\n";

                }

        if ( gender == "Ů��" ) {
                if ( per>=10&&per<=29 )
                        return ( look_level_girl[per-10]);
                else if (per>29)
                       return ( look_level_girl[20]);
                else return "����������ûʲô���\n";

                }
        else return "";
//      else return "����������ûʲô���\n";
}

int look_living(object me, object obj)
{
        string str, limb_status, ridemsg, pro;
        mixed *inv;
        mapping my_fam, fam;
// added for bian by mon.
        mapping ofamily;
        string ogender,orace;
        int oage;

        if(obj->query_temp("d_mana")>0)
        {
                ofamily=obj->query_temp("family");
                ogender=obj->query_temp("gender");
                orace=obj->query_temp("race");
                oage=obj->query_temp("age");
        }
        else
        {
                ofamily=obj->query("family");
                ogender=obj->query("gender");
                orace=obj->query("race");
                oage=obj->query("age");

     if(obj->query("life/live_forever") )
       {
          if (!obj->query("fake_age")) obj->set("fake_age",oage);
         if (oage > obj->query("fake_age")) oage=obj->query("fake_age");       }
     if (obj->query_condition("makeup"))
     if (obj->query("fake_age_x"))
         oage=obj->query("fake_age_x");
//done with fake_age
     }
        if( me!=obj && obj->visible(me) && environment(me) &&
            !environment(me)->query("no_look") )
                message("vision", me->name() + "�������㿴����֪����Щʲô���⡣\n", obj);

        str = obj->long();

        str = replace_string(str, "$n", me->name());
        str = replace_string(str, "$N", obj->name());
    str = replace_string(str, "$C", RANK_D->query_respect(obj));
    str = replace_string(str, "$c", RANK_D->query_rude(obj));
        str = replace_string(str, "$R", RANK_D->query_respect(me));
        str = replace_string(str, "$r", RANK_D->query_rude(me));


        pro = (obj==me) ? gender_self(ogender) : gender_pronoun(ogender);

        if(obj->query_temp("d_mana")==0 || obj->query_temp("is_character")) {

        if( orace=="����"
        &&      intp(oage) )
                if(oage<10) {
                        str += sprintf("%s��������Ȼ������ʮ�ꡣ\n", pro);
                }
                else{
                        str += sprintf("%s��һλ%s�����%s��\n", pro, chinese_number(oage / 10 * 10),RANK_D->query_respect(obj));
                }

        //check about wife and husband
        if((obj->parse_command_id_list())[0]==me->query("couple/id") ) {
                if( (string)me->query("gender")=="Ů��" ){
                str += sprintf("%s������ɷ�\n", pro);
                }
                else{
                        str += sprintf("%s��������ӡ�\n", pro);
                }
        }
        // If we both has family, check if we have any relations.
        if( obj!=me
        &&      mapp(fam = ofamily)
        &&      mapp(my_fam = me->query("family"))
        &&      fam["family_name"] == my_fam["family_name"] ) {

                if( fam["generation"]==my_fam["generation"] ) {
                        if( ogender == "����" )
                                str += sprintf( pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                        else
                                str += sprintf( pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( member_array(my_fam["master_id"],
                            obj->parse_command_id_list())>-1  )
                                str += pro + "�����ʦ����\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += pro + "�����ͬ�ų�����\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                                str += pro + "�����ʦ����\n";
                        else
                                str += pro + "�����ʦ�塣\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += pro + "�����ͬ������\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += pro + "����ĵ��ӡ�\n";
                        else
                                str += pro + "�����ʦֶ��\n";
                }
        }



//here, if per>=100, no rong-mao description, it'll be necessary sometimes.
//return special looking first if he/she has one.

        if( obj->query("looking") ){
                str += pro + (string)obj->query("looking") + "\n";
        } else {
          string looking= per_status_msg((int)obj->query("age"),
                 (int)obj->query_per(), ogender);
              if( strlen(looking)>1 && obj->query("per") < 100 )
                         str += pro + looking;
        }

        ridemsg = ride_suffix(obj);
        if (ridemsg)
                str += pro + "��" + ridemsg + "��\n";

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n" : "ֻ��%s��\n%s\n",
                                pro, implode(inv, "\n") );
        }

        }

        me->start_more(str);

        if( obj!=me
        &&      living(obj)
        &&      random((int)obj->query("bellicosity")/10) > (int)me->query_per() ) {
                write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
                COMBAT_D->auto_fight(obj, me, "berserk");
                return 1;
        }

//this part is  taken from attack.c


        return 1;
}

string inventory_look(object obj, int flag)
{
        string str;
        str = obj->short();
        if( obj->query("equipped") )
                str = HIC "  ��" NOR + do_query(obj);
        else if( !flag )
                str = "    " + str;
        else return 0;
        return str;
}


int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("����ֻ�л����ɵ�һƬ��ʲôҲû�С�\n");

        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));

                return 1;
        }
        if (env->query("no_look"))
                return notify_fail("��ʲôҲ��������\n");
        if( mapp(exits = env->query("exits")) && exits[arg] && !undefinedp(exits[arg]) ) {
                if( (objectp(exits[arg]) && env=exits[arg]) ||
                    objectp(env = load_object(exits[arg])) ) {
                        look_room(me, env);
                        if(!me->query("env/invisibility") && random(3)==0
                                && env!=environment(me) ) {
                            string msg=peep_msg[random(sizeof(peep_msg))];
                            msg=replace_string(msg,"$N",me->name());
                            tell_room(env, msg);
                        }
                } else {
                  return notify_fail("��ʲôҲ��������\n");
                }
                return 1;
        }
        return notify_fail("��Ҫ��ʲô��\n");
}
string do_query(object obj)
{
        string str,units;

        units =obj->query("unit");
        str = obj->short();
        if (obj->query("armor_type"))
        switch( obj->query("armor_type") ) {
                case "cloth":
                case "armor":
                        str = "��һ"+ units + str;
                        break;
                case "boots":
                        str = "���ϴ���һ" + units + str;
                        break;
                case "head":
                case "neck":
                case "wrists":
                case "finger":
                case "hands":
                        str ="����һ"+ units + str;
                        break;
                case "waist":
                        str = "��������һ"+units+str;
                        break;
                case "flower":
                        str = "ͷ�ϴ���һ"+units+str;
                        break;
                default:
                        str = "װ����"+str;
                        }
        else
        if( obj->wield() )
                if (obj->query("skill_type")=="throwing")
                str ="���ϴ���"+str;
                else
                str ="�ֳ�һ" + units + str;
        return str;
}
int help (object me)
{
        write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]

���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���

HELP
);
        return 1;
}


