       //by dewbaby
 
#include <ansi.h>
inherit ROOM;
        
void create()
       { 
          set ("short", HIM"������"NOR); 
         set ("long", @LONG 
        
һ����������軨��ķ��䡣�ƺ��ܾ�û����ס����
��һ�ۿ�ȥ����Ȼ�ɾ��ú��޻ҳ����㿴��������
��ͷ��һ�Ź�����Ϣ�õ���ľ���(bed)������ȥ
��ܰ���ʡ�
LONG); 
       
        set("no_fight", 1); 
        set("item_desc", ([ /* sizeof() == 1 */ 
        "bed" : "һ����ľ��齣�����ȥ�ɾ�����������������һ��˯�⡣(gosleep,gobed,bed)��  ",
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
              message_vision(HIY "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n\n" NOR, me); 
              me->move(__DIR__"bed"); 
                  message_vision(HIY "\nɳ������һ����$N���˽�����\n" NOR, me); 
                      return 1; 
}

