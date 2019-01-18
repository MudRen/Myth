//Creat by waiwai@2000/10/31

#include <ansi.h>
inherit NPC;
//inherit F_VENDOR;

string ask_me(); //����ask_me
int do_gu(string arg); 
int do_dapi(string arg); 
int do_cuihuo(string arg); 
void reward(object me); 

void create()
{
set_name("������", ({ "zhou tiejiang", "zhou", "tiejiang", "smith"}) );
set("title", WHT"�������ϰ�"NOR);
set("shen_type", 1);
set("gender", "����" );
set("age", 33);
set("long", "������������ǯ��סһ����ȵ�����Ž�¯�С�\n");

        set("combat_exp", 10000);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("literate", 40);
        set("kee", 600);
        set("sen", 600);
        set("max_kee", 600);
        set("max_sen", 600);
        set("attitude", "friendly");
/*
        set("vendor_goods", ([
               "1": "/d/obj/weapon/dagger/dagger.c",
                "2": "/d/obj/weapon/axe/tiefu.c",
                "3": "/d/obj/weapon/hammer/hammer",
                "4": "/d/obj/weapon/fork/fork",
            	"5": "/d/obj/weapon/stick/bintiegun",
                "6":"/d/obj/weapon/whip/tielian",
                "7": "/d/obj/armor/niupi",
                "8": "/d/obj/weapon/sword/changjian",
                "9": "/d/obj/weapon/blade/blade",
                "10": "/d/obj/weapon/spear/tieqiang",
                "11": "/d/obj/weapon/staff/chanzhang",
                "12" : "/d/faith/obj/axe",
                "13" : "/d/faith/obj/pickaxe",
        ]) );

set("inquiry", ([ 
"����" : (: ask_me :), 
"work" : (: ask_me :), 
]));
*/
setup();

        carry_object("/d/obj/cloth/linen")->wear();
        carry_object("/d/obj/weapon/hammer/hammer")->wield();
}

void init()//���嶯��
{
//add_action("do_vendor_list", "list");
add_action("do_gu", "gu"); 
add_action("do_dapi", "dapi"); 
add_action("do_cuihuo", "cuihuo"); 
}

string ask_me() 
{ 
object me = this_player(); 

if (me->query("combat_exp") > 200000) //���EXP�Ƿ����200000
return "�����ϸ����δ�������˰ɣ�"; 

if(me->query("title") == "��ͨ����")
    return "������ͨ���ղ��������⣡"; 

if (me->query("PKS") > 1) //����Ƿ����ɱ�˼�¼
return "ɱ�����ֻ�Ҫ��ɣ�û�ţ�����"; 

if (me->query("daoxing") < 100000) //���DX�Ƿ�С��100��
return "���������ô���ܴ����������"; 

if (me->query("kee") < 50) //�����
return "�㻹��Ъ����ɣ�Ҫ�ǳ��������ҿɳе�����"; 

if (me->query_temp("smith/gu")) //�����
return "����ķ��䣬����ô��ĥ��(gu)��"; 

if (me->query_temp("smith/dapi")) 
return "�������������û��(dapi)��"; 

if (me->query_temp("smith/cuihuo")) 
return "�����һ�»�(cuihuo)��Ϲ����ʲô��"; 

switch(random(3))//���������������
{ 
case 0: 
me->set_temp("smith/gu", 1); 
return "�ã�"+me->name()+"����ҹ�һ�������(gu)"; 

case 1: 
me->set_temp("smith/dapi", 1); 
return "�����ɣ�����Ҵ�һ������(dapi)��"; 

case 2:
me->set_temp("smith/cuihuo", 1); 
return "ȥ���Ұ���Щ�ճ�¯�Ĵ�һ�»�(cuihuo)��"; 

} 
} 

int do_gu(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("��������æ��\n"); 

if (! me->query_temp("smith/gu")) 
{ 
message_vision(""+me->name()+"��͵͵������ķ�������˼���硣" 
"������$N��"+me->name()+"��ȵ����������Ҹ�ʲô��\n", 
this_object(), me); 
return 1; 
} 

message_vision(""+me->name()+"����ķ��ƴ������������$N���˵��˵�ͷ��\n", 
this_object(), me); 
reward(me); 
return 1; 
} 

int do_dapi(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("��������æ��\n"); 

if (! me->query_temp("smith/dapi")) 
{ 
message_vision(""+me->name()+"���𼸿���������������˵ࡣ" 
"������$N��"+me->name()+"��ȵ������£��Ҹ�ʲô��\n", 
this_object(), me); 
return 1; 
} 

message_vision(""+me->name()+"���Ŵ��ӶԸճ�¯�Ļ��ȵ����������ô��ţ�" 
"$N���š���һ��������ȥ��Щ���⡣\n", 
this_object(), me); 
reward(me); 
return 1; 
} 

int do_cuihuo(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("��������æ��\n"); 

if (! me->query_temp("smith/cuihuo")) 
{ 
message_vision(""+me->name()+"�ճ���һ������õ����ӣ�" 
"������$N��"+me->name()+"��ȵ������£�����Ҹ㻵�ˡ�\n", 
this_object(),me);
return 1; 
} 

message_vision(""+me->name()+"����ǯ����һ��������ӣ������ˮ" 
"�أ����ꡱ��һ��������ð��\n", 
me); 
reward(me); 
return 1; 
} 

void reward(object me) //�������������佱�ͣ��Ƴ����
{ 
object money; 

me->delete_temp("smith/gu"); 
me->delete_temp("smith/dapi"); 
me->delete_temp("smith/cuihuo"); 

money = new("/obj/money/silver"); 
money->set_amount(20 + random(10)); 
money->move(this_player()); 
message_vision("$N��"+me->name()+"�������Ǹ���Ĺ�Ǯ��\n", 
this_object(), me); 
//if (me->query("combat_exp") < 200000) 
//{
//me->add("potential", 5); 
//me->add("combat_exp", 50 + random(20)); 
//me->add("daoxing", 50 + random(20)); 
//} 
me->receive_damage("kee", 30); 
me->start_busy(8); 
} 

