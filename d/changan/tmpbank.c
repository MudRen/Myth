// tmpbank.c
//cglaem...12/19/96.

inherit BANK;

void create()
{
	set("short", "����Ǯׯ��ʱ���´�");
	set("long", @LONG

��Ϊ�������ݱ����գ����ϰ�Ϊ�˿ͷ���ƣ�����ˮ�ӱ���
ʱ������һ�����´������ɳ���������ƹ��������ڴ�����
���´�ֻ��һ���ª��Сľ��ſڹ���һ������(paizi)��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"south" : __DIR__"eside1",
	]));

	set("item_desc", ([
		"paizi": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

check		���ʡ�
deposit		��
withdraw	ȡ�
convert		�һ�Ǯ�ҡ�

TEXT
	]) );

set("objects",([
  __DIR__"npc/tiesp" : 1,
 ]));
    
	setup();
}
