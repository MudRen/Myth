// rewritten by snowcat.c 4/4/1997
// room: /d/nuerguo/eastriver1.c

inherit ROOM;

void create ()
{
  set ("short", "��ĸ�Ӷ���");
  set ("long", @LONG

�γ���ˮ��տտ������һ��С��(river)����ǰ�档����������
Ů�����㿴��һ������û����Ҳû�аڶɣ���ˮ�ڴ˴��������
ֱ���˹�ȥ�е�Σ�ա�

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "river" : "������ĸ�ӺӰɣ���������ɫ�Ĺ���
��˵����ĸ�Ӻ�ˮ���˻ỳ�С�
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"eastriver2",
  "east" : __DIR__"start",
]));
  set("outdoors", __DIR__"");

  setup();
}
