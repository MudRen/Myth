// Room: /d/moon/fengxue/lake.c
// edit by xuanzi

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

    �ӷ�ѩ��һ·������ͻȻһƬ�̲����������׳����
ˮ���������ǰ�������ػ�һ�档��ˮ��ɼ��ף���Ŀ��
ȥ������������֮�У��ƺ���һ��С����

LONG);
        set("no_clean_up", 0);
    set("outdoors","fengxue");
  set("exits",([
    "north" : __DIR__"fxtd",
    "west" : __DIR__"lake-side",
]));

        setup();
}
void init()
{
  add_action("do_swim","swim");
}

int do_swim()
{
  object me;
  me = this_player();
  message_vision("$N���������ѩ���죬���ɵ��е���ԥ��\n",me);
 if (!me->query_temp("fengxue/aska"))
  {
    return notify_fail("��ô�ߵķ��ˣ����ı������ˣ�\n");
  } 
  message_vision("$N�뵽����������ǰ�棬ҧ�������һ�����ֽŲ��ã���ǰ��ȥ��\n",me);
  me->move(__DIR__"island");
  message_vision("�����������ˣ�$Nһ������ɳ̲�ϡ�\n",me);
  return 1;
}

