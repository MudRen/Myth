// Room: some place in ��ţ����
// uphill3.c

inherit ROOM;

void create()
{
  set ("short", "��ʯϪ");
  set ("long", @LONG

����������һ�Σ�ɽ·������ô�����ˡ�·�Ի�������һ��
СϪ��СϪ���Ϫˮ�峹���ס�Ϫ�е�С��������ȥ������
���Ӳ��д����������ɵĽ�����ż����ֻС��ɹ�����������
��Ȫ�����������֡�
LONG);
set("exits", ([ /* sizeof() == 4 */
"northeast" : __DIR__"uphill4",
"southdown": __DIR__"uphill2",
"northwest": __DIR__"baixi",
]));

        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
}

int valid_leave (object me, string dir)
{
        if (dir == "northwest"){
                message_vision ("$N������ȣ�������СϪ�С�\n",me);
        }
  return 1;
}

