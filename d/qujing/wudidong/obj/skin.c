// skin.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��Ƥ",({"ren pi", "skin", "pi", "renpi"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","
���̸������

\t���ҽ��ڶ��꣬�䲻�������Ҳ����������֮�顣����һ��������������
�����ģ��պ�ص��б������Ÿ��������е�������һ����������и�ϵ����������
���ܲ�֮�����ɶ�������һϸ����Ω�д�����������Ρ��������ܽ�����������һ��
��֮�ˣ���������Ѱ���ڼ飬������á��³�֮�գ��������б����������᲻ʳ�ԡ�
���»��ܣ���������֪����Īν��֮��ԤҲ��

\t \t \t \t \t \t ��ӿ���˶��ס�
		   \n");
		set("material", "paper");
		set("unit","��");
		set("value", 0);
	}
}

void init()
{
    if(userp(this_player()))
        add_action("do_tear", "tear");
}
 
int do_tear(string arg){
        object ob,me;
        me=this_player();
        if( !this_object()->id(arg) ) return notify_fail("��Ҫ˺ʲô��\n");
        ob=new(__DIR__"letter");
        ob->move(me);
        message_vision("$N˺����Ƥ�������ó���һ��ֽ��չ�˿�����\n", me);
        destruct(this_object());
        return 1;               
}
