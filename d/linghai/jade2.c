       //by dewbaby
 
#include <ansi.h>
inherit ROOM;
        
void create()
       { 
          set ("short", HIM"凝玉轩"NOR); 
         set ("long", @LONG 
        
一间充满淡淡茶花香的房间。似乎很久没有人住过，
但一眼看去，依然干净得毫无灰尘。你看到房间最
顶头有一张供人休息用的橡木软榻(bed)。看上去
温馨舒适。
LONG); 
       
        set("no_fight", 1); 
        set("item_desc", ([ /* sizeof() == 1 */ 
        "bed" : "一张橡木软榻，看上去干净柔软，让你心里升起一阵睡意。(gosleep,gobed,bed)。  ",
      ]));
        set("exits", ([ /* sizeof() == 1 */ 
        "down" : __DIR__"jade", 
        "east" : __DIR__"huxin", 
      ])); 
        set("no_magic", 1); 
       
        setup(); 
      } 
       
      void init() 
      { 
              add_action("do_bed", "gosleep"); 
              add_action("do_bed", "gobed", ); 
              add_action("do_bed", "bed"); 
      } 
       
      int do_bed() 
      {       object me; 
              me=this_player(); 
              message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me); 
              me->move(__DIR__"bed"); 
                  message_vision(HIY "\n沙帐轻轻一动，$N钻了进来。\n" NOR, me); 
                      return 1; 
}

