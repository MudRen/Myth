// Room: /4world/entrance
inherit ROOM;

// int do_push(string);

void create ()
{
  set ("short", "��ʯ");
  set ("long", @LONG

�����ǻ���ɽ����һ��ƽ�ء�һ���ٲ���ɽ������ֱ�£�
к��һ����̶�������ǣ���һ�ɰ׺���ǧѰѩ�˷ɡ���
�ٲ�������һ���ʯͷ���ഫΪ���������������֪��˭��
�������һ��ʫ��

������������δ������ң�ãã�������˼���
���������Դ��̹��ƺ��ɣ����ٴ������Ǳ档

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/ourhome/npc/longear" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"houshan1",
  "southdown" : __DIR__"up2",
]));

    set("no_fight", 1);
    set("no_clean_up", 0);
  
setup();
          call_other( "/obj/board/pansi_ss", "???" );
        replace_program(ROOM);
}


int valid_leave(object me, string dir)
{
	object mbox;

	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "�㽫���佻�ظ��ʲ\n");
		destruct(mbox);
	}
	return 1;
}

