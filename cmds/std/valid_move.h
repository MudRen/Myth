// mon 9/25/97

int valid_move(object me)
{
        if( me->over_encumbranced() )
                return notify_fail("��ĸ��ɹ��أ��������á�\n");

        if( me->is_busy() )
                return notify_fail("��Ķ�����û����ɣ������ƶ���\n");

        if( me->query_temp("no_move") )
//              return notify_fail("�㱻��ס�ˣ����ﶯ���ˣ�\n");
// mon 8/11/97. change the fail message since not only dingshen
// can lead to no_move.
                return notify_fail("�����ڲ����ƶ���\n");
        return 1;
}
