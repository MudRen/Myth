//Cracked by Roath


inherit NPC;
#include <ansi.h>

void greeting(object me);

void create()
{
        set_name("���ϰ�", ({"boss dachang", "boss", "dachang"}));
        set("long",@LONG
���ϰ�ԭ����󳦣������ǳ�����������å�����ң�������
֮һ���дα�����ʹ����Դ����𣬰�������֮�ʶ�ʷ���ơ���
�������ܴ����˵Ĺ���ʱ���Ȼ���򡣴Ӵ˷ܷ����飬Ǳ��ϰ�䣬
�Ĳ����䲻�ͺ���Ȼ�º����̣����ڳɾ��˽���ľ��档����
������󳣣������ۣ�ٲȻ�¹����ˡ�
LONG);
        set("title", "�����޼�");
        set("gender", "����");
        set("age", 44);
        set("per",18);
        set("kee", 800); 
        set("max_kee", 800);
        set("sen", 200);
        set("max_sen", 200);
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("chat_chance", 3);
        set("chat_msg", ({
         "���ϰ������ȵ�������ү����ʵ�ںܲ�˳�ۣ�ȥ���ɡ�\n",
         "���ϰ���һ������������ɨ�����ڳ���ÿһ���ˡ�\n",
         "���ϰ�˵����ĸ��������һֻ����\n",
        }));

        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);

        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("gold", 1);
}

void init()
{
    call_out("greeting", 1, this_player());
    ::init();
}
void greeting(object who) {
  tell_object(who,"���ϰ��������㿴����֪����Щʲô���⡣\n");
}
