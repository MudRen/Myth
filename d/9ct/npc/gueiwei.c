// ��λ����

inherit NPC;

#include <ansi.h>

int send_back(object me);
string ask_shuizhu();
string ask_qingsuojian();

void create()
{
        set_name(HIC"��λ����"NOR, ({ "guiwei tianzun", "tianzun"}) );
        set("gender", "����" );
        set("age", 45);
        set("long",
                "������ͥ��һ��ʹ��,�����(ask tianzun about back)���ء�\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("inquiry", ([
                "��ȥ" : (: send_back :),
                "back" : (: send_back :),
                "��λ" : (: send_back :),
        ]) );
        set_skill("literate", 100);
        set_skill("dodge", 100);
        setup();
        carry_object("/obj/money/gold");
        carry_object("/d/obj/armor/jinjia")->wear();
}

int send_back(object me)
{
        me=this_player();
        command("sigh " + me->query("id"));
        command("say " + "֪����֪ȥ...�������ðɣ�����ͻ�ȥ�ɡ�\n");
        tell_object(me,"\n��λ����˦�����䣬������ǰһ��...\n\n��ƮƮȻ�� ...\n\n");
        if(!me->query("dream_place")) me->move("/d/calvin/lanling/center");
        else me->move((string)me->query("dream_place"));
        return 1;
}
void init()
{
object who=this_player();
add_action("do_error", "mark");
add_action("do_error", "fly");
// add_action("do_error", "perform");
//add_action("do_error", "cast");
add_action("do_error", "fight");
//add_action("do_error", "kill");
}

int do_error(string arg)
{
object who = this_player();
message_vision("��Ҫ����Ŷ,С�ı�����������ӣ�\n",who);
return 1;
}

