// propose.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object who;
	string *wives;
	mapping wiv;

        if(me->query("age") < 17)
           return notify_fail("С����һ�����ȥ��\n");

        if (!arg) return notify_fail("��Ҫ��˭��飿\n");

        if (me->query("gender")=="Ů��")
                return notify_fail("ֻ�����˲����������飡\n");

        if (!objectp(who=present(arg,environment(me))))
                return notify_fail("����û������ˡ�\n");

        if (!who->is_character())
                return notify_fail("�������"+who->name()+"��ʲôѽ��\n");

        if (who==me)
                return notify_fail("��ʲô��Ц������\n");

        if (me->query("married"))
                return notify_fail("�ٺ٣�����" + me->query("couple/name") + "������\n");

        if (!living(who))
                return notify_fail("��...�㻹���Ȱ�"+who->name()+"Ū�Ѱɡ�\n");

        if (who->query("gender")=="����")
                return notify_fail("�ţ����̬�𣿣���\n");

if ((me->query("bonze/class")=="bonze")||(who->query("bonze/class")=="bonze"))
return notify_fail("�������Ĵ�Կգ����֮�¾����˰ɡ�\n");

        if (who->query("married"))
                return notify_fail("�������˰ɣ�"+who->name()+"���з�֮������\n");
	
        message_vision("$N����$n�����ظ�˵��ֻҪ��޸��ң��������ʲô�Ҿ���ʲô��\n", me, who);

        me->set("proposing",1);
        me->set("propose_target", getuid(who));
        who->set("proposed",1);
        who->set("propose_man", getuid(me));

        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : propose <ĳ��>
 
���ָ������������飬����߱���Ϊ���ԣ���Ů����Ӧ��˫��������ͤ�Ǽǣ�
�����һ������ʽ��������ʽ�ɻ��ˡ�

���ָ������ģ�marry
��س�������ģ�marriage

HELP);
    return 1;
}

