// Room: /d/4world/tudi.c
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

һ��СС�����������﹩�����ع�������������(statue)����
̨�ϰ���Щ��Ʒ���򣬻���Щ���ƽ�������顣����ܾ�������
��ʲô�춯����̨����֧���򷢳������Ĺ��ߡ�
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "statue" : "��������ܹ��ƶ�(push)��\n",
]));


  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"west2",
]));

  setup();
}
void init()
{
        add_action("do_push", "push");
}

int do_push(string arg)
{       
        object me,m;
        me=this_player();

        if ( !arg || ((arg != "���ع���")
		&&(arg != "��������") && (arg!="statue")) )
                return notify_fail("��Ҫ��ʲô��\n");

	if (objectp(present("mud baby", environment(me)))) {
		write("����������Ц������˵���������أ���ʲô�ƣ�\n");
		return 1;
	}

		message_vision("$Nʹ�������������ع������������ŵ�����\n",me);

	        m=new(__DIR__"npc/niwawa");
		m->move(environment(me));
		write("�����¡�����֮�������ĳ�������������\n");
                return 1;
}

