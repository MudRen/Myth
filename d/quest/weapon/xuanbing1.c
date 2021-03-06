//m_weapon .....tianjianshi.c
//xuanbing.c

#include <ansi.h> 
inherit ROOM;

void init() 
{
        add_action("do_change_id", "change_id");
       
        seteuid(getuid()); 
}

void create()
{
        set("short", "玄兵古洞");
        set("long",
                "这里是玄兵古洞，四面洞壁之上结满了石英的柱状结晶体，显得\n"
                "十分漂亮。前方一个巨大的炉子前站着一位长髯老者正看着炉火想着\n"
                "什么心事，旁边几个彪形大汉正挥舞着锤头敲打着一块似乎总也烧不\n"
                "红的什么金属。旁边仔细的放着几把刚刚出炉的兵器。那种骇人的杀\n"
                "气竟是从这些兵器上散发出来的。\n"

        );
        set("exits", ([
                "out" : __DIR__"xuanbing",
        ]));
        set("objects" , ([
               __DIR__"npc/tianjianshi" : 1,

             ]) );
        setup();
//        replace_program(ROOM);
}

//added by wuyou

int  do_change_id(string arg) 
{ 
       int i;
       string w_id, new_id, w_name; 
       object me=this_player(); 
       
       if (!me->query("weapon/make"))
          return notify_fail("你现在没有自制武器。\n");

       w_name=me->query("weapon/name");
       w_id=me->query("weapon/id");

       if( !arg || arg == "")  
           return notify_fail("请用 change_id <新英文名> 来改名。\n"); 
           
       if( sscanf(arg, "%s", new_id) != 1) 
           return notify_fail("请用 change_id <新英文名> 来改名。\n"); 
             
        i = strlen(new_id);
        while(i--)
                if( new_id[i]<'a' || new_id[i]>'z' )
                        return notify_fail("对不起，兵器的英文代号只能用英文字母。\n");

        me->set("weapon/id", new_id);
        me->start_busy(3);
        me->receive_damage("kee", 500);
        me->receive_damage("sen", 500);
                  
        write(""+w_name+"的英文名称改动成功。\n"); 
        return 1; 
} 
     

