//�±�ˮ��̶
//By junhyun@SK
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 
void create() 
       { 
        set("short", "��̶ˮ��"); 
        set("long", @LONG

�����̶ˮ���׶һ�������ȫ���Ҵ̣����ҧ���� 
�����ڹ����ű����̶ˮ�����ţ�����ֻ�����뿪 
�����ط�.....


LONG
        );


       set("exits", ([ 
        "south" : __DIR__"tandim", 
        "west" : __DIR__"tandim", 
        "north" : __DIR__"tandim", 
        "east" : __DIR__"tandim", 
      ])); 
       
       set("coor/x",10); 
       set("coor/y",-620); 
       set("coor/z",-20); 
       setup(); 
      } 
      void init() 
      { object ob; 
       if( interactive( ob = this_player())) 
       call_out("blowing", random(10) + 1, ob); 
       add_action("do_chop","chop"); 
      } 
      int blowing(object ob) 
      { 
       int i; 
       int damage; 
              if(  ob && environment(ob) == this_object()) 
       { 
       tell_object(this_object(), HIW "\n\n����ı�ˮ����߶����µĴ����磡��\n\n" NOR); 
       COMBAT_D->report_status(ob,1); 
       ob->receive_wound("kee", random(20)+10); 
       if( environment(ob) == this_object()) 
       call_out("blowing",random(10)+1, ob); 
       } 
       else 
       return 1; 
      } 
      void reset() 
      { 
       ::reset(); 
              remove_call_out("blowing"); 
              delete("exits/east"); 
      } 
      int valid_leave(object me, string dir) 
      { 
              remove_call_out("blowing"); 
       return 1; 
      }

