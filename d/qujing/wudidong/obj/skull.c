// skull.c
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("������",({"ku lou", "skull", "kulou"}));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","
\tһ��������������á������е�࣬�������ġ��㲻���������ôС��һ������
�ܱ�����ͷ����˭��ô���й�������ô�ѿ���һ�����ó�������ϸ���һ�����㷢��
����ͷ�ǹ���Щ�ɶ�����֪��ʲô�Ź֡�\n");
                set("unit","��");
                set("value",5000);
                set("material","iron");
                set("wield_msg","$Nץס$n�ı��ӣ�����úܲ�˳�֣���Ҳ�����硣\n"
);
                set("unwield_msg","$N��$n�Ż������У�˦��˦��ʹ���֡�\n");
        }
        init_hammer(5);
        setup();
}
void init()
{
        add_action("do_pull", "pull");
}
int do_pull(string arg){
        object ob, me;
        me=this_player();
 
        if (!arg || (arg != "scalp"))
                return notify_fail("��Ҫ��ʲô��\n");
             else {
                ob=new(__DIR__"lingpai");
                ob->move(me);
                message_vision("$N����һ�������õ�ͷ�ǹǣ����������������Ƭ�����ڵ��ϡ�\n", me);
	    message_vision("$N������Ƭ����һ�����ƣ�������������������\n", me);
	    destruct(this_object());
                return 1;
                }
}
