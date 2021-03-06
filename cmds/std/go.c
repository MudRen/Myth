// go.c

//#pragma save_binary
#include <ansi.h>
inherit F_CLEAN_UP;
#include "/cmds/std/valid_move.h";

mapping default_dirs = ([
        "north":                "北",
        "south":                "南",
        "east":                 "东",
        "west":                 "西",
        "northup":              "北边",
        "southup":              "南边",
        "eastup":               "东边",
        "westup":               "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":             "东边",
        "westdown":             "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":                   "上",
        "down":                 "下",
        "out":                  "外",
        "enter":                "里",
        "left":                 "左",
        "right":                "右",
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
                          xx=18+random(5);  yy=18+random(5);//随出现方位！
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

        if( !arg ) return notify_fail("你要往哪个方向走？\n");

        if(!valid_move(me)) return 0;

        env = environment(me);
        if(!env) return notify_fail("你哪里也去不了。\n");

        if( !mapp(exit = env->query("exits")) || !exit[arg] ||  undefinedp(exit[arg]) ) {
                if( query_verb()=="go" || query_verb()=="gogo" )
                        return notify_fail("这个方向没有出路。\n");
                else
                        return 0;
        }

        dest = exit[arg];

        if (dest && objectp(dest))
            obj = dest;
        else if( !(obj = load_object(dest)) )
                return notify_fail("你要去的区域还没有连通。\n");
        else if( !(obj = find_object(dest)) )
                return notify_fail("无法移动。\n");

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
          ridemsg = ridee->query("ride/msg")+"着"+ridee->name();
        else
          ridemsg = "";

        if(ridee && !valid_move(ridee))
           return notify_fail("你的座骑走动不了。\n");

if(me->is_ghost()&&domain_file(base_name(environment(me)))!="death")
 {
                write(BLU"突然间阴风阵阵，你耳边响起一阵空洞而又阴森的声音:‘回来哟，回来哟!’\n"NOR);
                write(HIW"一阵白雾将你裹了起来，你又回到了鬼门关\n"NOR);
                me->move("/d/death/gate");
                return 1;
 }
        if( me->is_fighting() ) {
                mout = ridemsg + "往" + dir + "落荒而逃了。\n";
                min = ridemsg + "跌跌撞撞地跑了过来，模样有些狼狈。\n";
        } else {
                //Jiz. 02/11
                if( ridee && ridee->query("bird") ) {
                        mout = ridemsg+ "往" + dir + "飞去。\n";
                        min = ridemsg+ "飞了过来。\n";
                } else {
                        mout = ridemsg+ "往" + dir + "离开。\n";
                        min = ridemsg+ "走了过来。\n";
                }
        }

        change_position(me,arg);

        if( !wizardp(me) || !me->query("env/invisibility") )
        {
                if (environment(me) && environment(me)->query("no_look"))
                        message( "vision", "一个模糊的影子" +  mout, environment(me), ({me}) );
                else
                        message( "vision", me->name() + mout, environment(me), ({me}) );
        }
        if( (! ridee || ridee->move(obj)) && me->move(obj, silent) ) {
                me->remove_all_enemy();
                if( !wizardp(me) || !me->query("env/invisibility") ) {
                                if (environment(me) && environment(me)->query("no_look"))
                                        message( "vision", "一个模糊的影子" +  min, environment(me), ({me}) );
                                else
                                        message( "vision", me->name() + min, environment(me), ({me}) );
                }
                me->set_temp("pending", 0);
                // added by snowcat, to fix the bug of recursive move of mutual follow + move to same room
                if (env != obj)
                        all_inventory(env)->follow_me(me, arg);
                if (ridee)
                        tell_object (me,"你"+min);
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
        tell_object(me, "看来该找机会逃跑了．．．\n");
        if( me->query_temp("no_move") ) {
          tell_object (me, "可你被定住了，逃不掉！\n");
          return;
        }

        if( random(me->query_skill("dodge")/10 + me->query("kar")) < 10 ) {
           tell_object(me, "你逃跑失败。\n");
           return;
        }

        main(me, directions[random(sizeof(directions))], 0);
}

nosave mapping r_dirs = ([
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
                } //中间起步
                  else {
                        xx=me->query_temp("position/xx");
                        yy=me->query_temp("position/yy");
                        zz=me->query_temp("position/zz");
                }
         if (zz !=0) return "你不在地面上，怎么出去？！\n";

         if ( env->query("position_max") && (env->query("position_max") >= 3 || env->query("position_max") <= 8))
                 pos =env->query("position_max");
                 else pos =3;
             pos -=1;//hehe!注意
             switch (arg)
            {
                 case "north":
                 case "northup":
                 case "northdown":
                       if (xx!=20 || yy!=20+pos)
                          return "你不在北边方位，怎么去呀！\n";
                          break;
                 case "east":
                 case "eastup":
                 case "eastdown":
                       if (xx!=20+pos || yy!=20)
                          return "你不在东边方位，怎么去呀！\n";
                          break;
                      
                 case "west":
                 case "westup":
                 case "westdown":
                        if (xx!=20-pos || yy!=20)
                          return "你不在西边方位，怎么去呀！\n";
                          break;
                 case "south":
                 case "southup":
                 case "southdown":
                        if (xx!=20 || yy!=20-pos)
                          return "你不在南边方位，怎么去呀！\n";
                          break;
                 case "northeast":
                        if (xx!=20+pos || yy!=20+pos)
                          return "你不在东北角边方位，怎么去呀！\n";
                          break;
                 case "northwest":
                        if (xx!=20-pos || yy!=20+pos)
                          return "你不在东北角方位，怎么去呀！\n";
                          break;
                 case "southeast":
                        if (xx!=20+pos || yy!=20-pos)
                          return "你不在东南角方位，怎么去呀！\n";
                          break;
                 case "southwest":
                        if (xx!=20-pos || yy!=20-pos)
                          return "你不在西南角方位，怎么去呀！\n";
                          break;
                 default:
                      if (xx!=20 || yy!=20)
                          return "你不在此出口方位，怎么去呀！\n";
                     break;
            }
          return "none";
}



int help(object me)
{
        write(@HELP
指令格式 : go <方向>

让你往指定的方向移动。

HELP
    );
    return 1;
}


