inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "�����");
        set("long", HIG@LONG
��ˮ�峺͸������ʱ���Կ�����β������ˮ�档��ˮ��ͷ��һ
�����ٲ�����������������ٲ���ɽ��ֱ����£������ĺ��������
����һ���ʯ����д�����������
LONG
        );
        set("item_desc", ([
           "��̶":  "��̶�������ף�����С��СϺ����������������\n",
           "pond":  "��̶�������ף�����С��СϺ����������������\n",
        ]));
        set("exits", ([ /* sizeof() == 4 */
   "north" : __DIR__"taolin", 
   "northwest" : __DIR__"pond", 
   "southwest" : __DIR__"lake2", 
   "west" : __DIR__"lake",]));
}

void fish_notify(object obj, int i)
{
   object me, room, fish, *inv, bait;

   me = this_player();
        
   switch (i) { 
   case 0:
      bait = present("qiu yin", obj);
      if(!objectp(bait)) {
      message("vision",me->name() + "�ͳ���" + obj->name() + "�ַ��˻�ȥ��\n", environment(me), me);
      tell_object(me, obj->name() + "��û�ж���ô���Ե����أ� \n");
      }
   else {
      message_vision("$N�Ӷ���һ�£�" + obj->name() + "�ڿ��л���һ��Ư���Ļ��ߣ��㹳������ˮ�С� \n" , me);
      destruct(bait);
      remove_call_out("do_fishing");              
      call_out("do_fishing", 5, me);
      }
   break;
   }
   return;
}

void do_fishing(object me)
{
   object       fish;

   if(me && environment(me) == this_object()) {
   message_vision("$N�ܿ��ֳ�����һ����ˣ� " , me);
   switch (random(3)) {
      case 0:
         message_vision("ȴʲô��û�������� \n", me);
         break;
      case 1:
         message_vision("��ֱ����������������� \n", me); 
         fish = new("/d/quest/tulong/obj/fish1");
         me->set_temp("m_success/���",1);
         fish->move(environment(me));
         remove_call_out("kill_me");
         call_out("kill_me", 1, me);         break;
      case 2:
         message_vision("�㹳�ϵ���һ�����㣡�� \n", me);
         fish = new("/d/quest/tulong/obj/fish");
         fish->move(me);
         break;
      }
   }
   return;
}


