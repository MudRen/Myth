// sanjie wujiang0.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "�ڽ���");
  set ("long", @LONG

		��		��
		��		��
		��		��
		��		��
	
�����ڽ�����ˮ���˻��Ծ�Ӣ�ۣ������ɰ�תͷ�գ�������
Ц̸�С�һ������������������ڴˣ�����Ϊ�˼���������
��������һ��ʯ��
LONG);

  set("exits", ([
  "east" : __DIR__"wujiang1",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
        add_action("do_swim", "swim");
        add_action("do_koujian", "koujian");
}

int do_swim()
{
        object  me, horse;
	me = this_player();

message_vision(HIY "$N����һԾ�����뺣�С�ֻ��$Nʹ����ȫ�����������㲢�ã���һ������ε��˶԰���\n" NOR, me);
        me->move("/d/changan/eastseashore");
        message_vision(HIY "ֻ��$N����ʪ�����شӺ�������������\n" NOR, me);
        me->receive_damage("kee", 20);
        me->receive_damage("sen", 20);
        return 1;
}

int do_koujian (string arg)
{
  object me = this_player();
  object xiangyu = present("xiang yu",environment(me));

  if (arg != "xiangyu")
  {
    message_vision("ֻ��$N������ȥ����\n",me);
    tell_object(me,"����ߵ��˭��\n");
    return 1;
  }  

  message_vision("ֻ��$N������ȥ������"+
                 RANK_D->query_self(me)+
                 "ߵ�������ȹ���\n",me);

  if (xiangyu)
    message_vision("$N����һ�ѽ�$nС���Ƶ������������ز��ء�\n",xiangyu,me);
  else
  {
    message_vision(MAG"ʯ�������ط���һЩ��ɫ����\n"NOR,me);
    call_out("xiangyu_appear",10+random(10),me);
  }
  return 1;
}

void xiangyu_appear(object me)
{
  object xiangyu;

  if (environment(me) != this_object())
    return;

  if (present("xiang yu",environment(me)))
    return;

  me->start_busy(10);
  xiangyu = new (__DIR__"npc/xiangyu");
  xiangyu->move(environment(me));
  message_vision(MAG"һ����ɫ�������һ����������$N��\n"NOR,xiangyu);
}
