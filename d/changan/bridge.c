inherit ROOM;

void create ()
{
  set ("short", "��ˮ��");
  set ("long", @LONG

���Ÿ߿���ˮ֮�ϣ����ƷǷ��������Ժ�������ͣ�������
�ּ�̡����ϳ�ˮ������������Ϣ��������ˮ�峺���ף�ʱ
������Ծ��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sbridge",
  "north" : __DIR__"nbridge",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "bridge") ))
                return notify_fail("��Ҫ��������\n");
        else
message_vision("$N̾�˿�������һ�գ���������ȥ������\n",me);

if( me->query("family") && (string)me->query("family/family_name")!="���޵ظ�" ) {
                me->move(__DIR__"inwater");
		message_vision("ֻ�������̡�һ����$N�����ϵ���ˮ�У�\n",
me);
                return 1;
                }
                me->move("/d/death/gate");
		message_vision("�Ĵ��������磬�ֳ�$N��Ӱ�ӣ�\n", me);
                return 1;
}

