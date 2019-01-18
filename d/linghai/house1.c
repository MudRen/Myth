//by dewbaby
//house1
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", HIM"桃园"NOR); 
         set ("long", @LONG 
        
走出世外，踏入桃园。这里雾朦朦的，你什么都
看不清楚。只是似乎你离那琴声又近了些。你伸
出双手寻着石壁向前走去，每一步后都听得到清
水溅起的声音。这时，一阵琴声引着你朝北走去。
LONG); 
        
         
       setup();
}
void init()
{
       add_action("do_push","push");
}

int do_push(string arg)
{
       object me = this_player();
 
       if (arg != "door" ) return 0;
       if ((int)me->query_skill("force",1) < 200)
       return notify_fail("你的内功心法还不够，进入石门后可能会有生命危险！\n");
       if ((int)me->query_skill("dodge",1) < 200)
       return notify_fail("你的轻功还不够，真不知道你是怎么来到这里的!\n");
       message_vision("$N意外地推开了北面的石门，柳暗花明又一村!\n",me);
       me->move(__DIR__"masterroom");
       tell_room(environment (me), me->name() + "从桃园中走了进来。\n",({me}));
       return 1;
}
