
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat

inherit ROOM;
#include <obstacle.h>

void create ()
{
  set ("short", "���");
  set ("long", @LONG

�ʹ����������˸���������������ƣ������ǵ���������ƶ�
�䣬������һ����̨�ף������ǽ�����������̫����Ȼ��������
�����������Ȼ��������̬ׯ�ϡ�

LONG);

  set("exits", ([
        "south"   : __DIR__"baiyujie",
        "north"   : __DIR__"luanfeng",
        "east"   : __DIR__"dongdian",
        "west"   : __DIR__"xidian",
      ]));
  set("objects", ([
        __DIR__"npc/dachen1" : 1,
        __DIR__"npc/dachen2" : 1,
        __DIR__"npc/dachen3" : 1,
        __DIR__"npc/dachen4" : 1,
        __DIR__"npc/dachen5" : 1,
        __DIR__"npc/emperor" : 1,
       ]));

  set("no_fight",1);
  set("no_magic",1);
  setup();
}
void init()
{
        add_action("do_dianmao","dianmao");
}
int do_dianmao()
{
        object me=this_player();
       
        int size1 = sizeof(obstacles);

//         if ( me->query("obstacle/number") < size1)
//         return notify_fail("��־�͵��˵�ͷ˵�����������ȰѾ�ȡ������˵�ɡ�\n");
        
        if( ! me->query("dianmao") )
         return notify_fail("����޶���Ц��Ц�����ڻ�û��ʱ�䣬�����ǹ��������ɡ�\n");

          me->add("office_number",1);
          me->delete("dianmao");
          tell_object(me,"��������΢Ц��˵�����㱣�Ҵ����쳯���޽�ɽ���ӣ�\n");
          return 1;
}

int valid_leave (object who, string dir)
{
     if( who->query("laojun_jing") != 1 ) 
{
  if (dir == "east" || 
      dir == "west" )
//      dir == "north")
  {
    message_vision ("$N��ͷ������һ̽�����漸���������ͽ�$N�ܳ���\n",who);

    return notify_fail("");
  }
    if (dir == "south" )
     who->start_busy(1);
}
  return 1;
}

