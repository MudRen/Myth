//changan city

inherit ROOM;
#include <allcity.h>
#include <ansi.h>
int do_climb(string arg);
void create ()
{
  set ("short","ʮ�ֽ�ͷ");
  set ("long", @LONG

������ǳ����ǵ��ϲ����ģ��ϰ��������ȸ�ֽ����ڴˡ�һ��
Ρ��ߴ�Ĺ�¥������ǰ���뱱�����¥ң���Ӧ������33�ף�
����������ʮ���꣬¥���о޹�һ�棬ÿ������¡¡�Ĺ�����
��������յ���Դ��򳤰��ǵĴ��С�·�ڳ�ˮ����������
�˳����ϡ�·�߲�֪ʲôʱ������һ�Ŵ�����(tree)���̸���ڣ�
�Ѿ�����һ����ʷ�ˡ�
LONG);

        set("item_desc", ([
        "tree"  :   "һ��֦Ҷïʢ�Ĵ������������ƺ�������(climb)��ȥ��\n",
	]));
        set("exits", 
        ([
        "south" : "/d/city/zhuque-s1",
        "north" : __DIR__"xuanwu-n0",
        "west" : __DIR__"baihu-w1",
        "up" : __DIR__"jiuguan1",
        "east" : __DIR__"qinglong-e1",
        "down" : __DIR__"droproom",
        ]));
        set("objects", 
        ([
        WAI_OBJ"tree" : 1,
        __DIR__"npc/libai" : 1,
	"/d/qujing/wuzhuang/npc/zhangguolao": 1,
// 30        "/d/wizz/passion/npc/doudou": 1,
// 31  "/d/quest/li/litianwang.c": 1,
        ]));

	set("outdoors", 1);
       set("tsj_exst","west");
	setup();
}

void init()
{

	add_action("do_climb", "climb");


	//Modified by aeddy@2002/12/05	
	if( !userp(this_player()) ) return 0;

	if (!this_player()->query_temp("armor/cloth") && this_player()->query("race")=="����" ) {
		this_player()->add_temp("rumor/nocloth",1);

		if ((int)this_player()->query_temp("rumor/nocloth")>10) {
		if (!this_player() && !userp(this_player()) && !wizardp(this_player()) ) return;

	       if( random(10) == 0 )
		tell_room(this_object(),
		RED+log_id(this_player())+"��ɫ���ŵشӽ����㱼����������\n"NOR, this_player());

            }
	} 
}

int do_climb(string arg)
{
	int i;
	object me, *inv;
    
	me=this_player();
	inv = all_inventory(me); 
   
	if( !arg || arg!="up") return notify_fail("��Ҫ���ĸ���������\n");
	if(me->query_temp("ridee")) return notify_fail("������ﲻ������!\n");
   
	for(i=0;i<sizeof(inv);i++)
    
    	if(inv[i]->query("is_monitored"))
    	return notify_fail(inv[i]->query("name")+"���ܴ�������\n");
	if(me->query_condition("killer")) {
       message("vision",
        me->name() + "սս���������Ŵ��������̸���ƨ��һŤһŤ����������ͻȻһ���ҽУ��ֵ���������\n",
        environment(me), ({me}) );
        write("��սս���������Ŵ��������̸���������һ��С��ˤ�˸�����ʺ��\n");
        return 1;
	}

	if (me->query("gender")!="Ů��")
	message("vision",
        me->name() + "սս���������Ŵ��������̸���ƨ��һŤһŤ����������\n",
        environment(me), ({me}) );
	else if(me->query("age")<40&&me->query("per")>24)
	message("vision",
        me->name() + "����һ������ȹƮƮ�������Ӱ���ϴ�������\n",
        environment(me), ({me}) );
	else message("vision",
        me->name() + "սս������ץס����������ȥ��\n", environment(me), ({me}) );
                me->move(__DIR__"misc/chatroom");

	if (me->query("gender")!="Ů��")
        message("vision",
        me->name() + "�������������������\n",
                environment(me), ({me}) );
	else if(me->query("age")<40 && me->query("per")>24)
	message("vision",
	"һ������������㶨��һ����"+ me->name(1) + "�Ѿ���������������ǰ��\n",
        environment(me), ({me}) );
	else  message("vision", me->name(1) + "սս�����ش���������������\n", environment(me), ({me}) );   
	return 1;
}   
/*
void do_rumor(object me)
{
    if (!me)    return;
     if (!userp(me)) return;
    tell_room(this_object(),RED+me->name(1)+"("+me->query("id")+")��ɫ���ŵشӽ����㱼������\n"NOR,me);
}


int valid_leave(object me, string dir)
{
 
	if ( userp(me) && (dir == "east"||dir=="west"
		||dir=="north"||dir=="south"||dir=="down"
		||dir=="up") ) {
		TOPTEN_D->topten_checkplayer(me);
		WEAPONTOP_D->topten_checkplayer(me);
		}

	return ::valid_leave(me, dir);
}
*/