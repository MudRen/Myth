// go.c

//#pragma save_binary
#include <ansi.h>
inherit F_CLEAN_UP;
#include "/cmds/std/valid_move.h";

mapping default_dirs = ([
        "north":                "��",
        "south":                "��",
        "east":                 "��",
        "west":                 "��",
        "northup":              "����",
        "southup":              "�ϱ�",
        "eastup":               "����",
        "westup":               "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":             "����",
        "westdown":             "����",
        "northeast":    "����",
        "northwest":    "����",
        "southeast":    "����",
        "southwest":    "����",
        "up":                   "��",
        "down":                 "��",
        "out":                  "��",
        "enter":                "��",
        "left":                 "��",
        "right":                "��",
]);

string check_position_exits(object me,object env,string arg);
void create() { seteuid(getuid()); }
void change_position(object me,string arg)
{

         int xx,yy,zz;
         object ridee;
                   switch (arg)
            {
                 case "north":
                 case "northup":
                 case "northdown":
                            xx=20;  yy=18;
                           break;
                 case "east":
                 case "eastup":
                 case "eastdown":
                            xx=18;  yy=20;
                          break;

                 case "west":
                 case "westup":
                 case "westdown":
                            xx=22; yy=20;
                          break;
                 case "south":
                 case "southup":
                 case "southdown":
                          xx=20;  yy=22;
                          break;
                 case "northeast":
                          xx=18;  yy=18;
                          break;
                 case "northwest":
                          xx=22;  yy=18;
                          break;
                 case "southeast":
                          xx=18;  yy=22;
                          break;
                 case "southwest":
                          xx=22;  yy=22;
                          break;
                 default:
                          xx=18+random(5);  yy=18+random(5);//����ַ�λ��
                     break;
            }
            zz=0;
            me->set_temp("position",(["xx":xx,"yy":yy,"zz":zz,]));

            if (ridee = me->ride())
                    ridee->set_temp("position",(["xx":xx,"yy":yy,"zz":zz,]));
}


// follow will have silent=2, so as to reduce the CPU load.
int main(object me, string arg, int silent)
{
        mixed dest;
        string ridemsg, mout, min, dir,check;
        object env, obj, ridee;
        mapping exit;
        int valid;

        if( !arg ) return notify_fail("��Ҫ���ĸ������ߣ�\n");

        if(!valid_move(me)) return 0;

        env = environment(me);
        if(!env) return notify_fail("������Ҳȥ���ˡ�\n");

        if( !mapp(exit = env->query("exits")) || !exit[arg] ||  undefinedp(exit[arg]) ) {
                if( query_verb()=="go" || query_verb()=="gogo" )
                        return notify_fail("�������û�г�·��\n");
                else
                        return 0;
        }

        dest = exit[arg];

        if (dest && objectp(dest))
            obj = dest;
        else if( !(obj = load_object(dest)) )
                return notify_fail("��Ҫȥ������û����ͨ��\n");
        else if( !(obj = find_object(dest)) )
                return notify_fail("�޷��ƶ���\n");

        if(env->query("hellfireroom"))
                     {
        if((check=check_position_exits(me,env,arg))!="none")
            return notify_fail(check);
                              }

        valid=(int)env->valid_leave(me, arg);
        if( !valid ) return 0;
        if(valid>1) return 1;

        if( !undefinedp(default_dirs[arg]) )
                dir = default_dirs[arg];
        else
                dir = arg;

        // snowcat 12/20/97
        if (ridee = me->ride())
          ridemsg = ridee->query("ride/msg")+"��"+ridee->name();
        else
          ridemsg = "";

        if(ridee && !valid_move(ridee))
           return notify_fail("��������߶����ˡ�\n");

if(me->is_ghost()&&domain_file(base_name(environment(me)))!="death")
 {
                write(BLU"ͻȻ�������������������һ��ն�������ɭ������:������Ӵ������Ӵ!��\n"NOR);
                write(HIW"һ�������������������ֻص��˹��Ź�\n"NOR);
                me->move("/d/death/gate");
                return 1;
 }
        if( me->is_fighting() ) {
                mout = ridemsg + "��" + dir + "��Ķ����ˡ�\n";
                min = ridemsg + "����ײײ�����˹�����ģ����Щ�Ǳ���\n";
        } else {
                //Jiz. 02/11
                if( ridee && ridee->query("bird") ) {
                        mout = ridemsg+ "��" + dir + "��ȥ��\n";
                        min = ridemsg+ "���˹�����\n";
                } else {
                        mout = ridemsg+ "��" + dir + "�뿪��\n";
                        min = ridemsg+ "���˹�����\n";
                }
        }

        change_position(me,arg);

        if( !wizardp(me) || !me->query("env/invisibility") )
        {
                if (environment(me) && environment(me)->query("no_look"))
                        message( "vision", "һ��ģ����Ӱ��" +  mout, environment(me), ({me}) );
                else
                        message( "vision", me->name() + mout, environment(me), ({me}) );
        }
        if( (! ridee || ridee->move(obj)) && me->move(obj, silent) ) {
                me->remove_all_enemy();
                if( !wizardp(me) || !me->query("env/invisibility") ) {
                                if (environment(me) && environment(me)->query("no_look"))
                                        message( "vision", "һ��ģ����Ӱ��" +  min, environment(me), ({me}) );
                                else
                                        message( "vision", me->name() + min, environment(me), ({me}) );
                }
                me->set_temp("pending", 0);
                // added by snowcat, to fix the bug of recursive move of mutual follow + move to same room
                if (env != obj)
                        all_inventory(env)->follow_me(me, arg);
                if (ridee)
                        tell_object (me,"��"+min);
                return 1;
        }

        return 0;
}

void do_flee(object me)
{
        mapping exits;
        string *directions;

        if( !environment(me) || !living(me) ) return;
        exits = environment(me)->query("exits");
        if( !mapp(exits) || !sizeof(exits) ) return;
        directions = keys(exits);
        if (environment(me) && environment(me)->query("no_flee")) return;
        tell_object(me, "�������һ��������ˣ�����\n");
        if( me->query_temp("no_move") ) {
          tell_object (me, "���㱻��ס�ˣ��Ӳ�����\n");
          return;
        }

        if( random(me->query_skill("dodge")/10 + me->query("kar")) < 10 ) {
           tell_object(me, "������ʧ�ܡ�\n");
           return;
        }

        main(me, directions[random(sizeof(directions))], 0);
}

static mapping r_dirs = ([
        "north":        "south",
        "south":        "north",
        "east":         "west",
        "west":         "east",
        "northup":      "southdown",
        "southup":      "northdown",
        "eastup":       "westdown",
        "westup":       "eastdown",
        "northdown":    "southup",
        "southdown":    "northup",
        "eastdown":     "westup",
        "westdown":     "eastup",
        "northeast":    "southwest",
        "northwest":    "southeast",
        "southeast":    "northwest",
        "southwest":    "northeast",
        "up":           "down",
        "down":         "up",
        "enter":        "out",
        "out":          "enter",
]);



string query_reverse(string dir)
{
        if (undefinedp(r_dirs[dir]))
                return 0;

        return r_dirs[dir];
}

string query_chinese_dir(string dir)
{
        return default_dirs[dir];
}
string check_position_exits(object me,object env,string arg)
{
        string pos_name;
        int pos,xx,yy,zz;
        if (!me->query_temp("position"))
           {
                xx=20;yy=20;zz=0;
                } //�м���
                  else {
                        xx=me->query_temp("position/xx");
                        yy=me->query_temp("position/yy");
                        zz=me->query_temp("position/zz");
                }
         if (zz !=0) return "�㲻�ڵ����ϣ���ô��ȥ����\n";

         if ( env->query("position_max") && (env->query("position_max") >= 3 || env->query("position_max") <= 8))
                 pos =env->query("position_max");
                 else pos =3;
             pos -=1;//hehe!ע��
             switch (arg)
            {
                 case "north":
                 case "northup":
                 case "northdown":
                       if (xx!=20 || yy!=20+pos)
                          return "�㲻�ڱ��߷�λ����ôȥѽ��\n";
                          break;
                 case "east":
                 case "eastup":
                 case "eastdown":
                       if (xx!=20+pos || yy!=20)
                          return "�㲻�ڶ��߷�λ����ôȥѽ��\n";
                          break;
                      
                 case "west":
                 case "westup":
                 case "westdown":
                        if (xx!=20-pos || yy!=20)
                          return "�㲻�����߷�λ����ôȥѽ��\n";
                          break;
                 case "south":
                 case "southup":
                 case "southdown":
                        if (xx!=20 || yy!=20-pos)
                          return "�㲻���ϱ߷�λ����ôȥѽ��\n";
                          break;
                 case "northeast":
                        if (xx!=20+pos || yy!=20+pos)
                          return "�㲻�ڶ����Ǳ߷�λ����ôȥѽ��\n";
                          break;
                 case "northwest":
                        if (xx!=20-pos || yy!=20+pos)
                          return "�㲻�ڶ����Ƿ�λ����ôȥѽ��\n";
                          break;
                 case "southeast":
                        if (xx!=20+pos || yy!=20-pos)
                          return "�㲻�ڶ��ϽǷ�λ����ôȥѽ��\n";
                          break;
                 case "southwest":
                        if (xx!=20-pos || yy!=20-pos)
                          return "�㲻�����ϽǷ�λ����ôȥѽ��\n";
                          break;
                 default:
                      if (xx!=20 || yy!=20)
                          return "�㲻�ڴ˳��ڷ�λ����ôȥѽ��\n";
                     break;
            }
          return "none";
}



int help(object me)
{
        write(@HELP
ָ���ʽ : go <����>

������ָ���ķ����ƶ���

HELP
    );
    return 1;
}


