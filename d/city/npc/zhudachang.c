//zhudachang.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("���ϰ�", ({"boss dachang","dachang","boss"}));
        set("title","�����޼�");
        set("gender", "����" );
        set("age", 45);
        set("per",18);
        set("class","taoist");
        set("long", "���ϰ�ԭ����󳦣������ǳ�����������å�����ң�������
֮һ���дα�����ʹ����Դ����𣬰�������֮�ʶ�ʷ���ơ���
�������ܴ����˵Ĺ���ʱ���Ȼ���򡣴Ӵ˷ܷ����飬Ǳ��ϰ�䣬
�Ĳ����䲻�ͺ���Ȼ�º����̣����ڳɾ��˽���ľ��档����
������󳣣������ۣ�ٲȻ�¹����ˡ�\n");
        set("combat_exp", 25000);
        set("daoxing",25000);
        set("attitude", "peaceful");
        set_skill("unarmed",100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("literate",100);
        set_skill("spells", 100);
        set("max_kee", 700);
        set("max_gin", 700);
        set("max_sen", 700);
        set("max_force",800);
        set("force",800);
        set("max_mana",800);
        set("mana",800);
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}