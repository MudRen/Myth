// where.c
// 06-14-95

inherit F_CLEAN_UP;
int where_all();

int main(object me, string str)
{
	object ob, where, *ob_list;
	int i;

       if (me != this_player()) return 0;
     if (! SECURITY_D->valid_grant(me, "(immortal)")) return 0;
	if (!str)
		return where_all();
        notify_fail("ָ���ʽ��where <�������>\n"); 
	ob = find_player(str);
	if( !ob ) ob = find_living(str);

	if( !ob ) ob = LOGIN_D->find_body(str);
	/*  added by mon. 2/23/97 */

        if( !ob || !me->visible(ob)) {
		str = resolve_path(me->query("cwd"), str);
		ob_list = children(str);
		
		if(sizeof(ob_list)<1)
		    return notify_fail("Can't find such player or file.\n");

		for(i=0; i<sizeof(ob_list); i++) {
			if( !ob = environment(ob_list[i]) ) continue;
			printf("%O\n", ob );
		}
		return 1;
	}

//	if (!ob) return notify_fail("����û����ˡ�\n");

	where = environment(ob);
	if (!where) return notify_fail("�����("+file_name(ob)+
	   ")��֪��������Ү������\n");
	printf("%s(%s)������%s(%s).\n",
		(string)ob->name(),
		(string)ob->query("id"),
		undefinedp(where->query("short"))?
                  where->short():
                  where->query("short"),
		(string)file_name(where));
"/cmds/std/look.c"->look_room(me,where);
	return 1;
}

int where_all()
{
    string str;
    object *list;
    int i, j, ppl_cnt;
    object me, where;
        me = this_player();
        str = "�� " + MUD_NAME + "\n";
        str += "��������������������������������������������������������������������������\n";
        str += "ʹ�ô���      ��������          Ŀǰλ��      \n";
        str += "��������������������������������������������������������������������������\n";
        list = users();
    j = sizeof(list);
    while( j-- ) {
        where=environment(list[j]);
        // Skip those users in login limbo.
        if( !where ) continue;
        if (! me->visible(list[j]) ) continue;
        str = sprintf("%s%-14s%-18s%-s(%s)\n",
                                str,
                                list[j]->query("id"),
                                list[j]->query("name"),
            where->query("short"),
            file_name(where)
                        );
                }
        str += "��������������������������������������������������������������������������\n";
    me->start_more(str);
    return 1;
}


int help(object me)
{
	write(@HELP
ָ���ʽ: where <��ҵ� ID>

���ָ����������֪���Ŀǰ���ڵ�λ��.

HELP
	);
	return 1;
}

