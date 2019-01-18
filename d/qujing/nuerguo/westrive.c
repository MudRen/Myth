// rewritten by snowcat.c 4/4/1997
// room: /d/nuerguo/westriver.c

inherit ROOM;

void create()
{
  set("short", "������");
  set("long", @LONG

�ӱ����񴹱̣�ˮ��ܿ��ǳ��������һ��Сé�ݡ��紵��
��һ��С��������ػ�����ȥ���Ӱ��ȵú�̤ʵ���в���
�˴�����ͽ����ˮ���ӡ�

LONG
     );

  set("exits", ([
        "north" : __DIR__"maowu",
        "west"  : __DIR__"sanchalu",
      ]));
  set("outdoors", __DIR__"");

  setup();
}

void init()
{
    add_action("do_cross", "cross");
}

void in_river(object me, object room);

void walk_in()
{
  object room;
  object me;

  me = this_player();
  if (!(room = find_object(__DIR__"river")))
    room = load_object(__DIR__"river");
  if (room = find_object(__DIR__"river"))
  {
    message_vision ("$N����ţ�С�ĵ��߽�ˮ���\n",me);
    in_river(me, room);
  }
}

void in_river(object me, object room)
{
  me->move(room);
  tell_object(me,"\n�߽�������ŷ��ֺ����ȷ�ܿ�\n");
  call_out("in_danger", 15, me);
}

void in_danger(object me, object room)
{
  me->move(room);
  tell_object(me,"\nһ���˴�������һ�����ˮ�\n");
  call_out("arrive", 5, me);
}

void arrive(object me)
{
  me->move(__DIR__"eastriver3");
  message_vision ("$N������������˰���\n",me);
}

int do_cross(string arg)
{
  if( !arg || arg=="" )
    return 0;

  if( arg=="river" )
  {
    walk_in();
    return 1;
  }
  return 0;
}

void reset()
{
    object room;

    ::reset();
}
