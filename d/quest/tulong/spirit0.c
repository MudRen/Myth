inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "ɽ��");
        set("long", HIG @LONG �˴���Щϡ�����ľ����ǰ������һ��ǧ����䡢�����Ե�
ɽ�壬Χ��һ���Ĺȣ�����һ����̶��Ȫˮ�ӷ�䱼�����£�����
й��ֱ����̶�����м�ֻС��������̶�߷��衣�˴���������ʪ
�������ķΣ�����ȴ�������κ����Եĳ�·����������ֻ���Ĵ�
תת(around)���ˡ�
LONG
        ); 
        set("exits", ([
        ]) );

        set("objects", ([
        "/d/quest/tulong/npc/spirit1": 4,
        ]) );

        setup();
}
void init()
{
    add_action("do_west", "xifang");    add_action("do_catch", "catch");
    add_action("do_around", "around");

}

int do_around(string arg)
{
   object me, room;

   me = this_player(); 
   if (random(20)<10)
   { 
       tell_object(me, "��ת��תȥ��Ҳû�ҵ����ڣ�������·����\n\n");
       room = find_object(__DIR__"liechang");
       if(!objectp(room)) room=load_object(__DIR__"liechang");
       me->move(room);
       return 1;
   }
   else  
       tell_object(me, "�㷢�������ƺ�����·(xifang)��\n\n");   return 1;}
int do_catch(string arg)
{
   object spirit, me, room;

   me = this_player();
   if(!arg || arg != "С����" && arg != "spirit" ) return 0;
   spirit = present("spirit", this_object());
   if(!objectp(spirit)) return 0;

   switch ( random (7)) {
   case 0:
      message_vision("$N��ǰһ�ˣ�С��������һ����$N���˸��ա� \n", me); 
      break;
   case 1:
      message_vision("$N����һ�ˣ�С��������һ����$N���˸��ա� \n", me); 
      break;
   case 2:
      message_vision("$N����һ�ˣ�С��������һ����$N���˸��ա�\n", me); 
      break;
   case 3:
      message_vision("$N�����ҵ������ظ���С���飬����һת�۾Ͳ����ˡ���\n", me);
      break;
   case 4:
      message_vision("$N�������ϣ�С�������Ա�һ�ζ㿪��$N��$N���Ʋ�סˤ�˸�����ࡣ  \n", me);
      break;
   case 5:
      message_vision("$N������ŵس�С��������ȥ����Ӻ���ץס����С����������ǰһ�壬$Nû�ɹ���\n", me);
      break;
   case 6:
      message_vision("$N��ǰһ�ˣ�С������ǰһ�壬��$N���ֱ߷ɿ�ķ��˹�ȥ�� \n", me); 
      message_vision("$N��ͷ����С�������ܵķ���׷ȥ����\n", me); 
      message_vision("\nС������ת��ת��ٿ��һ�²�������Ӱ��\n\n", me); 
      message("vision", me->name() + "��������С����ٿ��һ��Ҳ��������Ӱ��\n", environment(me), me);
      room = find_object(__DIR__"outlet2");
      if(!objectp(room)) room=load_object(__DIR__"outlet2");
      me->move(room);
      destruct(spirit);
      break;
   }

   return 1;
}

int do_west(string arg)
{
        object me;
        object room;
        me = this_player();
        message_vision("$N�����ߵ�������ȥ . \n", me);

        room = load_object(__DIR__"spirit3");
        if(room) me->move(room);

        return 1;
}


