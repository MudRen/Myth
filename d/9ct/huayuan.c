// 九重天 御花园 by Calvin
// Modified by kuku@sjsh  2003.5.17

#include <ansi.h>
inherit ROOM;
#include "banned1.h"

void create ()
{
  set ("short", NOR"御花园"NOR);
  set ("long", @LONG

※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
※※※   这里是皇宫的后院 - "御花园",这里四季长青,其中最显眼的就是    ※※※
※※※   花园中间的那棵"千紫藤(qianzi teng)",它高耸入云,一眼看不到    ※※※
※※※   顶.以前各门派的宗师常常聚居此处传授弟子武功,不过近年来由于   ※※※
※※※   妖魔当道,师傅们只好远离故土,另寻安静悠闲之所在.              ※※※
※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※

LONG);
        set("exits", ([   
                "up": __DIR__"yi",
        ]));
        set("objects", ([   
        ]));

        set("9ctroom",1);  
        setup();
}

void init() 
{  
        object me=this_player();
        add_action("do_quit",banned_action);  
        add_action("do_cast","cast");
        add_action("do_exert","exert");
        if (me->query("env/invisibility"))  
            me->delete("env/invisibility");
}  


int do_quit(string arg) 
{  
        write("进来了就老老实实的吧，你只有一条路可走。\n");  
        if (wizardp(this_player())) write("禁止使用此命令。\n");  
                return 1;  
}   

int do_cast(string arg) { 
        if(!arg) return 0;
        if(arg !="transfer" ) write("你不能在这里用这条命令。\n");    
        command("cast transfer");
        return 1;
}

int do_exert(string arg) { 
        if(!arg) return 0;
        if(arg !="recover" && arg != "heal" && arg != "refresh") return 0;
        command("exert "+arg);  
}

int valid_leave(object me, string dir)
{
        object ridee;
        ridee=me->ride();

        if( dir=="up" && !userp(me)) 
                return 0; 

        if (dir=="up") {
                if( me->query_temp("ridee") )
                        return notify_fail(WHT"你还是先从坐骑上下来吧。\n"NOR);
        }

        me->set_temp("sky_enter_time",time()); 
        return ::valid_leave(me, dir);
}