// Room: /d/jjf/gate.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG

�����ǵ��������屦�Ĺ�ۡ��Ľ������ʦ����Ҳ�ܶࡣ��������
����ͷ�ߴ��ʯʨ�ӡ�������һ�û����������дУ��ڸ��˴���
Ժ�ӣ�����Ժ�������������ġ��ϱ��Ǹ��ճ���������ؽ�������
֮�ء�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"front_yard.c",
  "north" : "/d/city/qinglong-e2",
]));
	set("out_doors", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qinan" : 1,
]));
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me, string dir)
{
    if (dir == "south" ) {
	if (((string)me->query("family/family_name")=="������") 
	||	wizardp(me)
	||	me->query_temp("pending/jiangjun_answer")) {
		return ::valid_leave(me, dir);
        	}
		if(objectp(present("qin an", environment(me)))) {
            	return
notify_fail("�ذ��ȵ����������������Ҵ�֮�أ��кι��(answer)��\n");
    		}
		return 1;
	}
    	return 1;
	}

