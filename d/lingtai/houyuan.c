// Room: some place in ��ţ����
// houyuan.c

inherit ROOM;

void create()
{
  set ("short", "��Ժ");
  set ("long", @LONG

��Ժ֮�пտյ�����ֻ��һ��С��ʿ��ɨ��Ժ�ӡ�����һ������
��ɫ�ĸ�¥����Լ��������д�š��ؾ��������֡����ߺ��ϱ�
��һЩʦ�ֵܵ�ס����
LONG);
set("exits", ([ /* sizeof() == 4 */
"southwest": __DIR__"inside1",
"south": __DIR__"inside6",
"north": __DIR__"jingge",
"east": __DIR__"inside4",
]));
set("objects", ([
                __DIR__"npc/xiaodao": 1 ]) );
        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}

