// Room: /d/jjf/mishi.c

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG

������С�ݺܾ�û�������ˣ��������ǻҳ�����ǰ����һ��
��ľ�������Ϲ���һ����λ��������̨�ϵ���������ȼ����
LONG
        );
        set("item_desc", ([ /* sizeof() == 2 */
  "table" : "���϶��ǻң�ʲôҲ�����壮
",
  "��λ" : "��λ��д�ţ�����޳�֮λ��
",
]));
        set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"front_yard2",
]));
        set("objects", ([ /* sizeof() == 1 */
  "/d/obj/book/spearbook" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}



