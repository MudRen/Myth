inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "̶��");
        set("long",HIG @LONG ̶ˮ���������̶ˮ�������ͷ�����飬һֻ����һ�����
��������ľһ��һ������ˮ�е�����һ��������ͷ������������
����΢�����㶼��֪������û�������Ļ��ᡭ�������������뷨��
������(climb)�ɡ�
LONG
        );
        setup();
}

void init()
{
   add_action("do_climb", "climb");
   if(interactive(this_player()))
   call_out("do_flush",60,this_player());
}

int do_climb(string arg)
{
   object me, room;

   me = this_player();
   if(me->is_busy())
        return notify_fail("������û�գ�\n");
   switch (random(3)) {
   case 0:
      message_vision("$N�ֽŲ��õ���������������һ�룬һʧ����ˤ��������\n", me);
      me->receive_damage("kee",100);
      me->start_busy(5);
      break;
   case 1:
      message_vision("$N�ֽŲ��õ����������ۿ��쵽ͷ�ˣ����һʧ����ˤ��������\n", me);
      me->receive_damage("kee",100);
      me->start_busy(5);
      break;
   case 2:
      if(!arg || arg != "��" && arg != "up" ) 
          return 0;
      room = find_object("/d/quest/tulong/spirit9");      if(!objectp(room)) 
          room=load_object("/d/quest/tulong/spirit9");      me->move(room);
      message_vision("$N����ʪ���ܵش�ˮ������������\n", me);
      break;
   }
   return 1;
}

void do_flush(object me)
{
   object room;

   if(!me || environment(me) != this_object())
   return;
   tell_object(me,"\n��ͻȻ����̶���ˮ��Ȼ��������\n\n");
   tell_object(me,"ˮ������������̶�׵�һ��������ӿ������\n");
   tell_object(me,"������һƬ��ȫ�ĺڰ�֮�У����г����˿־塭��\n\n");
   room = find_object("/d/quest/tulong/lake");   if(!objectp(room)) room= load_object("/d/quest/tulong/lake");   me->move(room);
   tell_object(me,"��֪�����˶�ã�����ǰһ������ˮ�������˺��档\n\n");
}




