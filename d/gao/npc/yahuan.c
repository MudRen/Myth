// yahuan1.c

inherit NPC;
void create()
{
       set_name("Ѿ��", ({"yahuan"}));

set("long","һ��СѾ��������ɨ�ŷ�����\n��ʱ��ʱ�����·����ƺ�������ˣ�\n");
       set("gender", "Ů��");
       set("age", 16);
       set("attitude", "friendly");
	set("per", 25);
        set("shen_type", 1);
	set("combat_exp", 500);
set("inquiry", ([
"�·�": "�·��ϵĿ����Ҳ����ˣ�����\n",
"ʣ��": "�ԣ��ԣ��Ը�û�꣬��Ҳ���ߣ�\n",
"ʣ��": "�ԣ��ԣ��Ը�û�꣬��Ҳ���ߣ�\n",
"food": "�ԣ��ԣ��Ը�û�꣬��Ҳ���ߣ�\n",
]) );

	setup();
        carry_object("/d/gao/obj/pink_cloth")->wear();
}
int accept_object(object who,object ob)
{
        object m;
	if (ob->query("id")=="kouzi") {
message_vision("СѾ����$N˵���ף��������ҵ��ģ�����лл���ˣ�\n", who);
message_vision("СѾ������������һֻ�������ݵ�$N�����У�\n", who);
		command("smile");
		m=new("/d/gao/obj/kaoji");
		m->move(who);
		return(1);
         }
	else return(0);
}
