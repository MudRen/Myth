//Created by waiwai@2001/05/12

inherit ROOM;

void create()
{
	set("short", "����");
        set("long",@LONG

�����������鸮�ĳ�������������������Ʒ���豸Ӧ�о��У�����
��Ʒ������Ҳ���ܾ�ϸ��һ�۱�֪�ǹټҵ���Ʒ���������¯���յ�
�����ģ�һ���ջ�Ѿ����æ�ż��������ġ��������㡹��
LONG
        );

        set("exits", ([
		"west": __DIR__"road3",
                ]));

	set("objects", ([
		__DIR__"npc/maid": 	1,
		]) );

        setup();
        replace_program(ROOM);
}

