inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "�洬��");
        set("long", HIG@LONG 
һҶС��Ư���ں����ϣ�����Ⱥɽ���ƣ��羰ʮ��������С�ۺ�
С�����ɳ���һ�ˣ��������ʮ�־��²����ι̣����Ϻ����һ�Խ���
LONG
        );
        set("objects",([
                ]));
 
        set("no_fight", 1);
        setup();
}   

void init()
{
   add_action("do_sail", "sail");
   add_action("do_dive", "dive");
}

int do_dive()
{
   object me, room;
   me = this_player();

   if(me->query_temp("marks/gateplace")) {
      message_vision("$Nվ������������һ������һ�����������˺��\n\n", me);
      room = find_object(__DIR__"gongmen");
      if(!objectp(room))  room = load_object(__DIR__"gongmen");
      me->move(room);
      return 1;
   }
   return 0;
}

int do_sail()
{
   object me, land;
   int slvl;
   
   me = this_player();
   slvl = (int)me->query_str();
   land = find_object(__DIR__"lake2");
   if(!objectp(land))
      land=load_object(__DIR__"lake2");
   if (query("exits/up")) return 0;
   if(me->query_temp("m_success/���")) {
      if(me->query_temp("marks/gateplace")) {
         message_vision("$N��ӯ�ػ���С���������ؿ����˺��ߡ�\n",me);
         message("vision",me->name()+"��ӯ�ػ���С���������ؿ����˺��ߡ�\n",land); 
         me->delete_temp("marks/gateplace");
         set("exits/up", __DIR__"lake2");
         land->set("exits/down", __DIR__"boat"); 
         call_out("boat_leave", 10, land);
         return 1;
      }
      message_vision("$N���𴬽���ӯ�ذ�С��������Ķ�������\n", me);
      me->set_temp("marks/gateplace", 1);
      me->start_busy(3);
      return 1;
   }
   if(random(50) < slvl) {
      message_vision("С�������ؿ����˺��ߡ�\n", me);
      message("vision",me->name()+"����С���������ؿ����˺��ߡ�\n",land); 
      set("exits/up", __DIR__"lake2");
      land->set("exits/down", __DIR__"boat"); 
      call_out("boat_leave", 10, land);
      return 1;
   }
   message_vision("$N����Ŀ�ĵ��ں��ϻ���С���� \n", me);
   return 1;
}

void boat_leave(object land)
{
   if (query("exits/up")) delete("exits/up");
   if (land->query("exits/down")) land->delete("exits/down");
   message("vision","һ��΢�������С�������˰��ߡ�\n",this_object()); 
   message("vision","һ��΢�������С�������˰��ߡ�\n",land); 
}


