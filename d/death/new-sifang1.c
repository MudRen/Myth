// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "˾��");
  set ("long", @LONG

���ڹ��߰����������Ũ����ʱ�شӰ뿪�ŵ��ŷ�Ʈ����������
��ɢ��һЩ�ƾɵ���Ʒ�������������Ѿ��޷��ֱ������Щʲô
�����ˡ�
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"new-yinsi1",
]));
  set("hell", 1);

  setup();
}


